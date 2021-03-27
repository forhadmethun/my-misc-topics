package assignment.second;

public class Test {
    public static void main(String[] args) {
        Person person = new Person(); person.setName("albert");
        Employee employee = new Employee();employee.setName("robert");
        Faculty faculty =new Faculty();faculty.setName("david");
        Staff staff = new Staff();staff.setName("alen");
        Student student = new Student(); student.setName("jammy");
        System.out.println(person.toString());
        System.out.println(employee.toString());
        System.out.println(faculty.toString());
        System.out.println(staff.toString());
        System.out.println(student.toString());

    }
}
