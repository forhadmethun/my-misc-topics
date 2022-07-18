package topic;

import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

// create exchange named `Topic-Exchange`
// word separated by . (dot), * means single word, # means single or multiple word seperated by . (dot)
// create bindings `#.ac` for queue `Ac`, `*.mobile.*` for queue `Mobile`, `*.tv.*` for the queue `Tv`
// in this case it will work as broadcast, pub/sub
// so message sending to `Topic-Exchange` will be pushed to the queue `Ac` & `Mobile` but not for the queue `Tv`

public class Publisher {
    public static void main(String[] args) throws IOException, TimeoutException {
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");
        factory.setUsername("rabbitmq");
        factory.setPassword("rabbitmq");
        Connection connection = factory.newConnection();
        Channel channel = connection.createChannel();

        String message = "Sending message to topic-exchange, which has bindings for `ac`, `mobile` & `tv` but the message will go to `blah.mobile.ac` routing key, so only to mobile & ac";

        // no specific routing key, so it would be empty string, ot null
        channel.basicPublish("Topic-Exchange", "blah.mobile.ac", null, message.getBytes());
        channel.close();
        connection.close();
    }
}
