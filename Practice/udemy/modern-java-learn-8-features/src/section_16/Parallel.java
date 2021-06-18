package section_16;

import data.Student;
import data.StudentDataBase;

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

//todo: parallel doesn't perform better while need to do autoboxing!!
//todo: do not use parallel if mutable variable exists, then will produce wrong result!
public class Parallel {
    public static void main(String[] args) {
        System.out.println("Seq: ");
        long start = getCurrentTimeMillis();
        System.out.println(
                IntStream.rangeClosed(1, 1000000).sum()
        );
        System.out.println(getCurrentTimeMillis() - start);

        System.out.println("Para: ");
        start = getCurrentTimeMillis();
        System.out.println(
                IntStream.rangeClosed(1, 1000000).parallel().sum()
        );
        System.out.println(getCurrentTimeMillis() - start);

        System.out.println("Processors: " + Runtime.getRuntime().availableProcessors());

        parallelCheck();
    }

    public static void parallelCheck(){
        System.out.println("seq: ");
        long start = System.currentTimeMillis();
        StudentDataBase.getAllStudents()
                .stream()
                .map(Student::getActivities)
                .flatMap(List::stream)
                .distinct()
                .sorted()
                .collect(Collectors.toList());
        System.out.println(System.currentTimeMillis() - start);
        System.out.println("para: ");
        start = System.currentTimeMillis();
        StudentDataBase.getAllStudents()
                .stream()
                .parallel()
                .map(Student::getActivities)
                .flatMap(List::stream)
                .distinct()
                .sorted()
                .collect(Collectors.toList());
        System.out.println(System.currentTimeMillis() - start);

    }

    private static long getCurrentTimeMillis() {
        return System.currentTimeMillis();
    }
}
