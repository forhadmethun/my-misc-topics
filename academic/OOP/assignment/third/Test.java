package assignment.third;

import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Triangle triangle = new Triangle();
        double side1,side2,side3;
        System.out.println("Enter Three side length of a triangle: ");
        Scanner scanner = new Scanner(System.in);
        side1 = scanner.nextLong();
        side2 = scanner.nextLong();
        side3 = scanner.nextLong();

        triangle.setSide1(side1);
        triangle.setSide2(side2);
        triangle.setSide3(side3);
        System.out.println("Enter Color");
        String color;
        color = scanner.next();
        triangle.setColor(color);

        boolean filled;
        System.out.println("Filled?  true or false?");
        filled = scanner.nextBoolean();
        triangle.setFilled(filled);

        System.out.println(triangle.toString());
        System.out.println(triangle.getArea());
        System.out.println(triangle.getColor());
        System.out.println(triangle.isFilled());


    }
}
