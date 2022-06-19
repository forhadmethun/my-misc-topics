package com.fm.grpc.greeting.server;

import com.fm.grpc.*;
import io.grpc.stub.StreamObserver;

public class CalculatorServerImpl extends CalculatorServiceGrpc.CalculatorServiceImplBase {
    @Override
    public void calculate(CalculatorRequest request, StreamObserver<CalculatorResponse> responseObserver) {
        int number = request.getNumber();
        int k = 2;
        int N = number;

        while(N > 1) {
            if (N %k == 0) {
                responseObserver.onNext(
                    CalculatorResponse.newBuilder().setResult(k).build()
                );
                N = N / k;
            } else {
                k = k + 1;
            }
        }

        responseObserver.onCompleted();
    }

    @Override
    public void sum(SumRequest request, StreamObserver<SumResponse> responseObserver) {
        responseObserver.onNext(
            SumResponse.newBuilder()
                .setResult(request.getFirstNumber() + request.getSecondNumber()).build()
        );
        responseObserver.onCompleted();
    }

    @Override
    public StreamObserver<CalculatorRequest> avg(StreamObserver<CalculatorResponse> responseObserver) {
        return new StreamObserver<CalculatorRequest>() {
            int count = 0, sum = 0;
            @Override
            public void onNext(CalculatorRequest value) {
                count++;
                sum = sum + value.getNumber();
            }

            @Override
            public void onError(Throwable t) {
                responseObserver.onError(t);
            }

            @Override
            public void onCompleted() {
                System.out.println("[server] avg():");
                System.out.println(count);
                System.out.println(sum);
                CalculatorResponse value = CalculatorResponse.newBuilder().setResult(sum / count).build();
                System.out.println("avg: " + value.getResult());
                responseObserver.onNext(
                    value
                );
                responseObserver.onCompleted();
            }
        };
    }

    @Override
    public StreamObserver<CalculatorRequest> currentMax(StreamObserver<CalculatorResponse> responseObserver) {
        System.out.println("[inside currentMax()]");
        return new StreamObserver<CalculatorRequest>() {
            int max = Integer.MIN_VALUE;
            @Override
            public void onNext(CalculatorRequest request) {
                if (request.getNumber() > max) {
                    System.out.println("current max: " + max);
                        max = request.getNumber();
                    responseObserver.onNext(
                        CalculatorResponse.newBuilder().setResult(max).build()
                    );
                }
            }

            @Override
            public void onError(Throwable t) {
                responseObserver.onError(t);
            }

            @Override
            public void onCompleted() {
                responseObserver.onCompleted();
            }
        };
    }
}
