package direct;

import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;
import com.rabbitmq.client.DeliverCallback;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

public class Consumer {
    public static void main(String[] args) throws IOException, TimeoutException {
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");
        factory.setUsername("rabbitmq");
        factory.setPassword("rabbitmq");
        Connection connection = factory.newConnection();
        Channel channel = connection.createChannel();

        DeliverCallback callback = (consumerTag, message) -> {
            System.out.println("Message received from direct-exchange: " + new String(message.getBody()));
        };

        // Consumer doesn't need to know anything about exchange
        // Consumer only listens to Queue name, <not the bindings>
        channel.basicConsume("Ac", true, callback, consumerTag -> {
        });
    }
}
