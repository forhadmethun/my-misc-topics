package section_18;

import data.Student;
import data.StudentDataBase;

import java.util.Comparator;
import java.util.List;
import java.util.function.Consumer;

public class ComparatorExample {

    static Consumer<Student> printer = (s) -> System.out.println(s);
    static Comparator<Student> comparingByName = Comparator.comparing(Student::getName);
    static Comparator<Student> comparingByGpa = Comparator.comparingDouble(Student::getGpa);

    public static void sortByName(List<Student> studentList){
        studentList.sort(comparingByName);
        studentList.forEach(printer);
    }

    public static void sortByGpa(List<Student> studentList){
        studentList.sort(comparingByGpa);
        studentList.forEach(printer);
    }

    public static void comparatorChaining(List<Student> studentList){
        studentList.sort(comparingByName.thenComparing(comparingByGpa));
        studentList.forEach(printer);
    }

    public static void comparatorWithNullValue(List<Student> studentList){
        studentList.sort(Comparator.nullsFirst(comparingByName));
        studentList.sort(Comparator.nullsLast(comparingByName));
        studentList.forEach(printer);
    }


    public static void main(String[] args) {
        sortByName(StudentDataBase.getAllStudents());
        System.out.println();
        sortByGpa(StudentDataBase.getAllStudents());
        System.out.println();
        comparatorChaining(StudentDataBase.getAllStudents());
        System.out.println();
        comparatorWithNullValue(StudentDataBase.getAllStudents());
    }
}
