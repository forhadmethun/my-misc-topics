package com.food.ordering.system.order.service.application.rest;

import com.food.ordering.system.order.service.domain.dto.create.CreateOrderCommand;
import com.food.ordering.system.order.service.domain.dto.create.CreateOrderResponse;
import com.food.ordering.system.order.service.domain.dto.track.TrackOrderQuery;
import com.food.ordering.system.order.service.domain.dto.track.TrackOrderResponse;
import com.food.ordering.system.order.service.domain.ports.input.service.OrderApplicationService;
import java.util.UUID;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

@Slf4j
@RestController
@RequiredArgsConstructor
public class OrderController {
  private final OrderApplicationService orderApplicationService;

  @PostMapping
  public ResponseEntity<CreateOrderResponse> createOrder(@RequestBody CreateOrderCommand createOrderCommand) {
    log.info("Creating order for customer: {} at restaurant: {}", createOrderCommand.getCustomerId(),
        createOrderCommand.getRestaurantId());
    CreateOrderResponse createOrderResponse = orderApplicationService.createOrder(createOrderCommand);
    log.info("Order created with tracking id: {}", createOrderResponse.getTrackingId());
    return ResponseEntity.ok(createOrderResponse);
  }

  @GetMapping("/{trackingId}")
  public ResponseEntity<TrackOrderResponse> getOrderByTrackingId(@PathVariable UUID trackingId) {
    TrackOrderResponse trackOrderResponse =
        orderApplicationService.trackOrder(TrackOrderQuery.builder().trackingId(trackingId).build());
    log.info("Returning order status with tracking id: {}", trackOrderResponse.getTrackingId());
    return ResponseEntity.ok(trackOrderResponse);
  }
}
