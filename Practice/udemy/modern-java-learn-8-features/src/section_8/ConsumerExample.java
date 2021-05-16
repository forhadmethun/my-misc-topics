package section_8;

import data.Student;
import data.StudentDataBase;

import java.util.List;
import java.util.function.Consumer;

public class ConsumerExample {
    static Consumer<String> printStringConsumer = (s) -> System.out.println(s);
    static Consumer<Student> printStudentConsumer = (s) -> System.out.println(s);
    static Consumer<Student> printStudentNameConsumer = (s) -> System.out.print(s.getName());
    static Consumer<Student> printStudentActivitiesConsumer =
            (s) -> System.out.println(s.getActivities());

    final static List<Student> allStudents = StudentDataBase.getAllStudents();

    public static void main(String[] args) {
//        printStringConsumer.accept("ohMyGGooD");

//        printStudentName();

//        printStudentNameAndActivities();

        printStudentNameAndActivitiesUsingCondition();
    }

    private static void printStudentNameAndActivitiesUsingCondition() {
        allStudents.stream()
                .filter(s -> s.getGradeLevel() >= 3 && s.getGpa() >= 3.9)
//                .forEach(printStudentNameConsumer.andThen(printStudentActivitiesConsumer));
//                .forEach(s -> printStudentNameConsumer.andThen(printStudentActivitiesConsumer));
                .forEach(s -> printStudentNameConsumer.andThen(printStudentActivitiesConsumer).accept(s));
    }

    public static void printStudentName(){
        allStudents.forEach(printStudentConsumer);
    }

    private static void printStudentNameAndActivities() {
        allStudents.forEach(printStudentNameConsumer.andThen(printStudentActivitiesConsumer));
    }

}
