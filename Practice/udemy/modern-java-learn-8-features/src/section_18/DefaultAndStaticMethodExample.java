package section_18;

import java.util.Arrays;
import java.util.List;

interface Multiplier{
    int multiply(List<Integer> integers);
    default int size(List<Integer> integers){
        return integers.size();
    }
    static boolean isEmpty(List<Integer> integers){
        return integers != null && integers.size() > 0;
    }
}

class MultiplierImpl implements Multiplier{
    @Override
    public int multiply(List<Integer> integers) {
        return integers.stream()
                .reduce(1, (x, y) -> x * y);
    }
}

public class DefaultAndStaticMethodExample {
    public static void main(String[] args) {
        List<Integer> integers = Arrays.asList(1, 2, 3, 4, 5);
        Multiplier m = new MultiplierImpl();
        System.out.println("interface method: " +  m.multiply(integers));
        System.out.println("default method: " + m.size(integers));
        System.out.println("static method: " + Multiplier.isEmpty(integers));
    }
}
