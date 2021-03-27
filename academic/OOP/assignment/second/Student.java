package assignment.second;

public class Student extends Person{
    enum classStatus{
        FRESHMAN,
        SOPHOMORE,
        JUNIOR,
        SENIOR
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                '}';
    }
}
