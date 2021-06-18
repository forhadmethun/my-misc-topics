package section_18;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class DefaultMethodExample {
    public static void main(String[] args) {
        List<String> stringList = Arrays.asList("C", "B", "A", "E", "D");
        stringList.sort(Comparator.naturalOrder());
        System.out.println(stringList);
        stringList.sort(Comparator.reverseOrder());
        System.out.println(stringList);

    }
}
