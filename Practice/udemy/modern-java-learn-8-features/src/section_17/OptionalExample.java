package section_17;

import data.Student;
import data.StudentDataBase;

import java.util.Optional;

public class OptionalExample {
    // without optional
    public static String getStudentNameWithoutOptional(){
        Student student = StudentDataBase.studentSupplier.get();
        if (student != null){
            return student.getName();
        }
        return null;
    }

    // optional
    public static Optional<String> getStudentNameFromOptional(){
        Optional<Student> studentOptional = Optional.empty();// Optional.ofNullable(StudentDataBase.studentSupplier.get());
        if(studentOptional.isPresent()){
            return studentOptional.map(Student::getName);
        }
        return Optional.empty();
    }

    // ofNullable
    public static Optional<String> ofNullableExample(){
        Optional<String> stringOptional = Optional.ofNullable(null);
        return stringOptional;
    }

    // of
    public static Optional<String> ofExample(){
        Optional<String> stringOptional = Optional.of(null);
        return stringOptional;
    }

    // orElse

    public static String optionalOrElse(){
        Optional<Student> student = Optional
                .ofNullable(
//                        StudentDataBase.studentSupplier.get()
                        null
                );
        String s = student.map(Student::getName).orElse("Default");
        System.out.println(s);
        return s;
    }

    // orElseGet
    public static String optionalOrElseGet(){
        Optional<Student> student = Optional
                .ofNullable(
//                        StudentDataBase.studentSupplier.get()
                        null
                );
        String s = student.map(Student::getName)
                .orElseGet(() -> "Default");
        System.out.println(s);
        return s;
    }

    // orElseThrow

    public static String optionalOrElseThrow(){
        Optional<Student> student = Optional
                .ofNullable(
//                        StudentDataBase.studentSupplier.get()
                        null
                );
        String s = student.map(Student::getName)
                .orElseThrow(() -> new RuntimeException("No data found"));
        System.out.println(s);
        return s;
    }

    // isPresent
    public static void isPresentExample() {
        Optional<Object> optionalO = Optional.ofNullable(null);
        if (optionalO.isPresent()){
            System.out.println("Exists");
        }
        else {
            System.out.println("not exists");
        }
    }


    // ifPresent
    public static void ifPresentExample() {
        Optional<Object> optionalO = Optional.ofNullable("ifPresent");
        optionalO.ifPresent((o) -> {
            System.out.println(o);
        });
    }

    public static void main(String[] args) {
        String studentName = getStudentNameWithoutOptional();
        System.out.println(studentName);

        Optional<String> studentNameOpt = getStudentNameFromOptional();
//        System.out.println(studentNameOpt);
        if(studentNameOpt.isPresent()){
            System.out.println(studentNameOpt.get());
        }
        else{
            System.out.println("Student not found from opt");
        }

        System.out.println(ofNullableExample().isPresent());

        // throws exception as of always expects the value that is never null
//        System.out.println(ofExample());

        optionalOrElse();
        optionalOrElseGet();
//        optionalOrElseThrow();
        ifPresentExample();
        isPresentExample();
    }
}
