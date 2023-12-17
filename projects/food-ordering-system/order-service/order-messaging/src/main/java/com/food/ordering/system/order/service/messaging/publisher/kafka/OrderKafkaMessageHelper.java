package com.food.ordering.system.order.service.messaging.publisher.kafka;

import lombok.extern.slf4j.Slf4j;
import org.apache.kafka.clients.producer.RecordMetadata;
import org.springframework.kafka.support.SendResult;
import org.springframework.stereotype.Component;
import org.springframework.util.concurrent.ListenableFutureCallback;

@Slf4j
@Component
public class OrderKafkaMessageHelper {
  public <T> ListenableFutureCallback<SendResult<String, T>> getKafkaCallback(
      String paymentResponseTopicName, T requestAvroModel, String orderId, String requestAvroModelName) {
    return new ListenableFutureCallback<SendResult<String, T>>() {

      @Override
      public void onSuccess(SendResult<String, T> result) {
        RecordMetadata metadata = result.getRecordMetadata();
        log.info("Received successful response from kafka for order id: {}" +
                " Topic: {} Partition: {} Offset: {} Timestamp: {}",
            orderId,
            metadata.topic(),
            metadata.partition(),
            metadata.offset(),
            metadata.timestamp());
      }

      @Override
      public void onFailure(Throwable ex) {
        log.error("Error while sending requestAvroModel: {} " +
                "message {} to topic {}", requestAvroModelName, requestAvroModel.toString(),
            paymentResponseTopicName, ex);
      }
    };
  }
}