package section_17;

import data.Student;
import data.StudentDataBase;

import java.util.Optional;

public class MapFlatMapFilterExample {

    //filter
    private static void filter(){
        Optional.ofNullable(StudentDataBase.studentSupplier.get())
                    .filter(s -> s.getGpa() >= 3.5)
                    .ifPresent(s -> System.out.println(s.getName()));

    }

    //map
    private static void map(){
        Optional.ofNullable(StudentDataBase.studentSupplier.get())
                .filter(s -> s.getGpa() >= 3.5)
                .map(Student::getName)
                .ifPresent(s -> System.out.println(s));

    }

    //flat map
    private static void flatMap(){
        Optional.of(StudentDataBase.studentSupplier.get())
                .flatMap(Student::getBike)
                .ifPresent(System.out::println);
    }

    public static void main(String[] args) {
        filter();
        map();
        flatMap();
    }
}
