package assignment.second;

import java.util.Date;

public class Employee extends Person{
    String office;
    double salary;
    Date hired;

    @Override
    public String toString() {
        return "Employee{" +
                "name='" + name + '\'' +
                '}';
    }
}
