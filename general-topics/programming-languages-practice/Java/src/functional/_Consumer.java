package functional;

import java.util.function.Consumer;

public class _Consumer {
    static Consumer<String> print = str -> System.out.println(str);

    public static void main(String[] args) {
        print.accept("Forhad");
    }
}
