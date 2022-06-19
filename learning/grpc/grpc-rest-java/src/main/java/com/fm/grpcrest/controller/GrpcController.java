package com.fm.grpcrest.controller;

import com.fm.grpcrest.model.CoreServiceGrpc;
import com.fm.grpcrest.model.PingRequest;
import com.fm.grpcrest.model.PingResponse;
import com.fm.grpcrest.service.PingService;
import io.grpc.stub.StreamObserver;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.lognet.springboot.grpc.GRpcService;

@Slf4j
@GRpcService
@RequiredArgsConstructor
public class GrpcController extends CoreServiceGrpc.CoreServiceImplBase {
    private final PingService pingService;

    @Override
    public void ping(PingRequest request, StreamObserver<PingResponse> responseObserver) {
        responseObserver.onNext(pingService.ping(request));
        responseObserver.onCompleted();
    }
}
