package header;

import com.rabbitmq.client.AMQP;
import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.TimeoutException;

// create exchange named `Header-Exchange`
// key - value structured header, x-match key with value: any, all
// create bindings for `Tv` with arguments, x-match: any, item1: tv, item2: television
// create bindings for `Mobile` with arguments, x-match: any, item1: mob, item2: mobile
// create bindings for `Ac` with arguments,x-match: all, item1: ac, item2: mobile
// so message sending to `Header-Exchange` will be pushed to the queue based on the header

public class Publisher {
    public static void main(String[] args) throws IOException, TimeoutException {
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");
        factory.setUsername("rabbitmq");
        factory.setPassword("rabbitmq");
        Connection connection = factory.newConnection();
        Channel channel = connection.createChannel();

        String message = "Sending message to header-exchange, message for mobile & tv";

        Map<String, Object> headersMap = new HashMap<>();
        headersMap.put("item1", "mob");
        headersMap.put("item2", "television");

         var basicProperties = new AMQP.BasicProperties();
         basicProperties = basicProperties.builder().headers(headersMap).build();

        // no specific routing key, so it would be empty string, ot null
        channel.basicPublish("Header-Exchange", "", basicProperties, message.getBytes());
        channel.close();
        connection.close();
    }
}
