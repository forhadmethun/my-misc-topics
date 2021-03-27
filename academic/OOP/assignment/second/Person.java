package assignment.second;

public class Person {
    String name;
    String address;
    String phoneNumber;
    String email;

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                '}';
    }
}
