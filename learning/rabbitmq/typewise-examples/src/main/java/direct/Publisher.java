package direct;

import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

// create queue named `Ac`, `Mobile`, `Tv`
// create exchange named `Direct-Exchange`
// create bindings `ac` for queue `Ac`, `mobile` for queue `Mobile`, `tv` for queue `Tv`

public class Publisher {
    public static void main(String[] args) throws IOException, TimeoutException {
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");
        factory.setUsername("rabbitmq");
        factory.setPassword("rabbitmq");
        Connection connection = factory.newConnection();
        Channel channel = connection.createChannel();

        String message = "Sending message to `Ac` queue through direct-exchange, which has bindings `ac`";

        channel.basicPublish("Direct-Exchange", "ac", null, message.getBytes());
        channel.close();
        connection.close();
    }
}
