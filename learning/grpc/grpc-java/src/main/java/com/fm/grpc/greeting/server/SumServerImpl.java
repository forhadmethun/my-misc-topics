//package com.fm.grpc.greeting.server;
//
//import com.fm.grpc.*;
//import io.grpc.stub.StreamObserver;
//
//public class SumServerImpl extends SumServiceGrpc.SumServiceImplBase {
//    @Override
//    public void sum(SumRequest request, StreamObserver<SumResponse> responseObserver) {
//        responseObserver.onNext(
//            SumResponse.newBuilder()
//                .setResult(request.getFirstNumber() + request.getSecondNumber()).build()
//        );
//        responseObserver.onCompleted();
//    }
//
//}
