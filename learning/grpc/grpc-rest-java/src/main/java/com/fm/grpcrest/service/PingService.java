package com.fm.grpcrest.service;

import com.fm.grpcrest.model.PingRequest;
import com.fm.grpcrest.model.PingResponse;
import com.google.gson.Gson;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;

@Service
@Slf4j
public class PingService {
    public PingResponse ping(PingRequest request) {
        log.info("Received Ping message {}", new Gson().toJson(request));
        return PingResponse.newBuilder()
            .setTimestamp(request.getTimestamp())
            .setMessage("Pong")
            .build();
    }
}
