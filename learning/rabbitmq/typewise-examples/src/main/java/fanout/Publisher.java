package fanout;

import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

// create exchange named `Fanout-Exchange`
// create bindings `ac` for queue `Ac`, `mobile` for queue `Mobile`, not for the queue `Tv`
// in this case it will work as broadcast, pub/sub
// so message sending to `Fanout-Exchange` will be pushed to the queue `Ac` & `Mobile` but not for the queue `Tv`

public class Publisher {
    public static void main(String[] args) throws IOException, TimeoutException {
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");
        factory.setUsername("rabbitmq");
        factory.setPassword("rabbitmq");
        Connection connection = factory.newConnection();
        Channel channel = connection.createChannel();

        String message = "Sending message to fanout-exchange, which has bindings for `ac`, `mobile`";

        // no specific routing key, so it would be empty string, ot null
        channel.basicPublish("Fanout-Exchange", "", null, message.getBytes());
        channel.close();
        connection.close();
    }
}
