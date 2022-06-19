package com.fm.grpc.greeting.server;

import io.grpc.ServerBuilder;
import io.grpc.protobuf.services.ProtoReflectionService;

import java.io.IOException;

public class GrpcServer {
    public static void main(String[] args) throws IOException, InterruptedException {
        var port = 50051;
        var server = ServerBuilder.forPort(port)
            .addService(new GreetingServerImpl())
//            .addService(new SumServerImpl())
            .addService(ProtoReflectionService.newInstance())
            .addService(new CalculatorServerImpl())
            .build();
        server.start();

        System.out.println("[starter] Server");
        System.out.println("[port] : " + port);

        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            System.out.println("[shutdown request]");
            server.shutdown();
            System.out.println("[stopped] Server");
        }));

        server.awaitTermination();
    }
}
