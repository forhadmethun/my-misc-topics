package com.fm.grpcrest.controller;

import com.fm.grpcrest.model.PingRequest;
import com.fm.grpcrest.service.PingService;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api")
@Slf4j
@RequiredArgsConstructor
public class PingController {
    private final PingService pingService;

    @PostMapping(path = "/ping", produces = MediaType.APPLICATION_JSON_VALUE)
    public ResponseEntity<?> ping(@RequestBody PingRequest request) {
        return ResponseEntity.ok(pingService.ping(request));
    }

}
