package functional;

import java.util.List;
import java.util.stream.Collectors;

public class _Stream {
    static class Person{
        @Override
        public String toString() {
            return "Person{" +
                    "name='" + name + '\'' +
                    ", gender=" + gender +
                    '}';
        }

        String name;
        Gender gender;

        public Person(String name, Gender gender) {
            this.name = name;
            this.gender = gender;
        }
    }
    enum Gender{
        MALE, FEMALE
    }

    public static void main(String[] args) {
        List<Person> persons = List.of(
                new Person("Forhad", Gender.MALE),
                new Person("Monday", Gender.FEMALE),
                new Person("Rahima", Gender.FEMALE),
                new Person("Karima", Gender.FEMALE),
                new Person("Matin", Gender.MALE)
        );

        persons.stream()
                .map(person -> person.name)
                .forEach(System.out::println);

        List<Person> males = persons.stream()
                .filter(person -> person.gender == Gender.MALE)
                .collect(Collectors.toList());
        males.forEach(System.out::println);
    }
}
