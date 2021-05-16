package section_7;

import java.util.Comparator;

public class ComparatorLambdaExample {
    public static void main(String[] args) {
        // before 8
        Comparator<Integer> comparatorOld = new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1.compareTo(o2);
            }
        };
        System.out.println(comparatorOld.compare(3, 2));

        Comparator<Integer> comparatorNew = (Integer o1, Integer o2) -> o1.compareTo(o2);
        System.out.println(comparatorNew.compare(3,2));
        Comparator<Integer> comparatorNew2 = (o1, o2) -> o1.compareTo(o2);
        System.out.println(comparatorNew2.compare(3,2));
    }
}
