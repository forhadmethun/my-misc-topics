package com.food.ordering.system.order.service.domain.dto.create;

import com.food.ordering.system.domain.valueobject.Money;
import java.util.UUID;
import javax.validation.constraints.NotNull;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Getter;

@Builder
@Getter
@AllArgsConstructor
public class OrderItem {
  @NotNull
  private final UUID productId;
  @NotNull
  private final Integer quantity;
  @NotNull
  private final Money price;
  @NotNull
  private final Money subTotal;
}
