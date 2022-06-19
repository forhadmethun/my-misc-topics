package com.fm.grpc.greeting.server;

import com.fm.grpc.GreetingRequest;
import com.fm.grpc.GreetingResponse;
import com.fm.grpc.GreetingServiceGrpc;
import io.grpc.stub.StreamObserver;

public class GreetingServerImpl extends GreetingServiceGrpc.GreetingServiceImplBase {
    @Override
    public void greet(GreetingRequest request, StreamObserver<GreetingResponse> responseObserver) {
        responseObserver.onNext(
            GreetingResponse.newBuilder()
                .setResult("Hello " + request.getFirstName()).build()
        );
        responseObserver.onCompleted();
    }

    @Override
    public StreamObserver<GreetingRequest> longGreet(
        StreamObserver<GreetingResponse> responseObserver) {

        return new StreamObserver<GreetingRequest>() {
            StringBuilder sb = new StringBuilder();
            @Override
            public void onNext(GreetingRequest request) {
                sb.append("Hello ");
                sb.append(request.getFirstName());
                sb.append("\n");
            }

            @Override
            public void onError(Throwable t) {
                responseObserver.onError(t);
            }

            @Override
            public void onCompleted() {
                responseObserver.onNext(
                    GreetingResponse.newBuilder().setResult(sb.toString()).build()
                );
                responseObserver.onCompleted();
            }
        };
    }

    @Override
    public StreamObserver<GreetingRequest> greetEveryone(StreamObserver<GreetingResponse> responseObserver) {
        return new StreamObserver<GreetingRequest>() {
            @Override
            public void onNext(GreetingRequest request) {
                responseObserver.onNext(
                    GreetingResponse.newBuilder().setResult("Hello " + request.getFirstName()).build()
                );
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
