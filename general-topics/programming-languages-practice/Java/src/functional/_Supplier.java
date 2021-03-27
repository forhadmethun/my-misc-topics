package functional;

import java.util.List;
import java.util.function.Supplier;

public class _Supplier {
    static Supplier<List<String>> getNames = () -> List.of("Forhad", "Hossain", "Methun");

    public static void main(String[] args) {
        System.out.println(getNames.get());
    }
}
