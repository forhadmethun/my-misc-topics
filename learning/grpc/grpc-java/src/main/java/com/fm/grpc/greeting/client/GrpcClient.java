package com.fm.grpc.greeting.client;

import com.fm.grpc.*;
import io.grpc.ManagedChannel;
import io.grpc.ManagedChannelBuilder;
import io.grpc.stub.StreamObserver;

import java.util.Arrays;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;

public class GrpcClient {
    public static void main(String[] args) throws InterruptedException {
        if (args.length == 0) {
            System.out.println("Need one argument to work");
            return;
        }
        var channel = ManagedChannelBuilder.forAddress("localhost", 50051)
            .usePlaintext()
            .build();
        switch (args[0]) {
            case "greet":
                doGreet(channel);
                break;
            case "long_greet":
                doLongGreet(channel);
                break; // client stream
            case "greet_everyone":
                doGreetEveryone(channel);
                break;
            case "sum":
                doSum(channel);
                break;
            case "avg":
                doAvg(channel);
                break;
            case "max":
                doMax(channel);
                break;
            case "calculator":
                doCalculator(channel);  // server streaming
                break;
            default:
                System.out.println("[invalid] keyword");
        }


        System.out.println("[shutdown] Client");
        channel.shutdown();
    }

    private static void doMax(ManagedChannel channel) throws InterruptedException {
        System.out.println("[inside] doMax()");
        var latch = new CountDownLatch(1);
        var stub = CalculatorServiceGrpc.newStub(channel);
        var stream = stub.currentMax(new StreamObserver<CalculatorResponse>() {
            @Override
            public void onNext(CalculatorResponse value) {
                System.out.println(value.getResult());
            }

            @Override
            public void onError(Throwable t) {
            }

            @Override
            public void onCompleted() {
                latch.countDown();
            }
        });

        Arrays.asList(1,2, 3, 1, 0, 5, 2, 7,8,100, 99,77, 150).forEach(number -> {
            stream.onNext(CalculatorRequest.newBuilder().setNumber(number).build());
        });
        stream.onCompleted();

        latch.await(3, TimeUnit.SECONDS);
    }

    private static void doGreetEveryone(ManagedChannel channel) throws InterruptedException {
        System.out.println("[inside] doGreetEveryone()");
        var stub = GreetingServiceGrpc.newStub(channel);
        var latch = new CountDownLatch(1);

        StreamObserver<GreetingRequest> stream = stub.greetEveryone(new StreamObserver<GreetingResponse>() {
            @Override
            public void onNext(GreetingResponse value) {
                System.out.println(value.getResult());
            }

            @Override
            public void onError(Throwable t) {

            }

            @Override
            public void onCompleted() {
                latch.countDown();
            }
        });


        Arrays.asList("a", "b", "c").forEach(c -> {
            stream.onNext(
                GreetingRequest.newBuilder().setFirstName(c).build()
            );
        });

        stream.onCompleted();
        latch.await(3, TimeUnit.SECONDS);
    }

    private static void doAvg(ManagedChannel channel) throws InterruptedException {
        System.out.println("[inside] doAvg()");
        var latch = new CountDownLatch(1);
        var stub = CalculatorServiceGrpc.newStub(channel);
        var stream = stub.avg(new StreamObserver<CalculatorResponse>() {
            @Override
            public void onNext(CalculatorResponse value) {
                System.out.println("avg: " + value.getResult());
            }

            @Override
            public void onError(Throwable t) {

            }

            @Override
            public void onCompleted() {
                latch.countDown();
            }
        });

        Arrays.asList(1,2, 3).forEach(number -> {
            stream.onNext(CalculatorRequest.newBuilder().setNumber(number).build());
        });
        stream.onCompleted();

        latch.await(3, TimeUnit.SECONDS);
    }

    private static void doLongGreet(ManagedChannel channel) throws InterruptedException {
        System.out.println("[inside] doLongGreet()");
        var stub = GreetingServiceGrpc.newStub(channel);
        StreamObserver<GreetingRequest> stream = stub.longGreet(new StreamObserver<GreetingResponse>() {
            @Override
            public void onNext(GreetingResponse response) {
                System.out.println(response.getResult());
            }

            @Override
            public void onError(Throwable t) {

            }

            @Override
            public void onCompleted() {

            }
        });
        Arrays.asList("Rahim", "Karim", "Basir").forEach(name -> {
            stream.onNext(GreetingRequest.newBuilder().setFirstName(name).build());
        });
        stream.onCompleted();

        new CountDownLatch(1).await(3, TimeUnit.SECONDS);
//        stub.longGreet();
//        stub.longGreeting()
//        stub.longGreeting();
//        var calculator = (CalculatorRequest.newBuilder().setNumber(120).build());
//        calculator.forEachRemaining(c -> {
//            System.out.println("[sum from client] " + c.getResult());
//        });
    }

    private static void doCalculator(ManagedChannel channel) {
        System.out.println("[inside] doCalculator()");
        var stub = CalculatorServiceGrpc.newBlockingStub(channel);
        var calculator = stub.calculate(CalculatorRequest.newBuilder().setNumber(120).build());
        calculator.forEachRemaining(c -> {
            System.out.println("[sum from client] " + c.getResult());
        });
    }

    private static void doSum(ManagedChannel channel) {
        System.out.println("[inside] doSum()");
        var stub = SumServiceGrpc.newBlockingStub(channel);
        var greet = stub.sum(SumRequest.newBuilder().setFirstNumber(20L).setSecondNumber(15L).build());
        System.out.println("[sum from client] " + greet.getResult());
    }

    private static void doGreet(ManagedChannel channel) {
        System.out.println("[inside] doGreet()");
        var stub = GreetingServiceGrpc.newBlockingStub(channel);
        GreetingResponse greet = stub.greet(GreetingRequest.newBuilder().setFirstName("forhad").build());
        System.out.println("[greeting from client] " + greet.getResult());
    }
}
