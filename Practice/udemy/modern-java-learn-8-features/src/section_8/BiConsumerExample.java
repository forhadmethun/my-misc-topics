package section_8;

import java.util.List;
import java.util.function.BiConsumer;

public class BiConsumerExample extends ConsumerExample{
    static BiConsumer<String, String> concatAndPrint = (s1, s2) -> System.out.println(s1.concat(s2));
    static BiConsumer<Integer, Integer> multiply = (m, n) -> System.out.println(m * n);
    static BiConsumer<Integer, Integer> divide = (m, n) -> System.out.println(m / n);
    static BiConsumer<String, List<String>> studentActivity = (s, h) -> {
        System.out.println(s + " : " + h);
    };

    public static void main(String[] args) {
        concatAndPrint.accept("first, ","second");
        multiply.andThen(divide).accept(10, 2);
        allStudents.forEach(s -> {
            studentActivity.accept(s.getName(), s.getActivities());
        });
    }
}
