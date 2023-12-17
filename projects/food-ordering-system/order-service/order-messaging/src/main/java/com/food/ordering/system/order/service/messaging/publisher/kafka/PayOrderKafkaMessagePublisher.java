package com.food.ordering.system.order.service.messaging.publisher.kafka;

import com.food.ordering.system.kafka.order.avro.model.RestaurantApprovalRequestAvroModel;
import com.food.ordering.system.kafka.service.KafkaProducer;
import com.food.ordering.system.order.service.domain.config.OrderServiceConfigData;
import com.food.ordering.system.order.service.domain.event.OrderPaidEvent;
import com.food.ordering.system.order.service.domain.ports.output.message.publisher.restaurantapproval.OrderPaidRestaurantRequestMessagePublisher;
import com.food.ordering.system.order.service.messaging.mapper.OrderMessagingDataMapper;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Component;

@Slf4j
@Component
@RequiredArgsConstructor
public class PayOrderKafkaMessagePublisher implements OrderPaidRestaurantRequestMessagePublisher {

  private final OrderMessagingDataMapper orderMessagingDataMapper;
  private final OrderServiceConfigData orderServiceConfigData;
  private final KafkaProducer<String, RestaurantApprovalRequestAvroModel> kafkaProducer;
  private final OrderKafkaMessageHelper orderKafkaMessageHelper;

  @Override
  public void publish(OrderPaidEvent domainEvent) {
    String orderId = domainEvent.getOrder().getId().getValue().toString();
    log.info("Received OrderPaidEvent for order id: {}", orderId);

    try {
      RestaurantApprovalRequestAvroModel restaurantApprovalRequestAvroModel = orderMessagingDataMapper
          .orderApprovalEventToRestaurantApprovalRequestAvroModel(domainEvent);
      kafkaProducer.send(
          orderServiceConfigData.getPaymentRequestTopicName(),
          orderId,
          restaurantApprovalRequestAvroModel,
          orderKafkaMessageHelper.getKafkaCallback(orderServiceConfigData.getPaymentResponseTopicName(),
              restaurantApprovalRequestAvroModel, orderId, "RestaurantApprovalRequestAvroModel")
      );
      log.info("RestaurantApprovalRequestAvroModel sent to kafka for order id: {}",
          restaurantApprovalRequestAvroModel.getOrderId());
    } catch (Exception e) {
      log.error("Error while sending RestaurantApprovalRequestAvroModel message" +
          " to kafka with order id: {}, error: {}", orderId, e.getMessage());
    }
  }
}
