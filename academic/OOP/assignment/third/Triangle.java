package assignment.third;

import assignment.first.GeometricObject;

import java.util.Date;

public class Triangle extends GeometricObject {
    double side1 = 1.0,side2 = 1.0,side3 = 1.0;
    Triangle(){

    }

    public Triangle(String color, boolean filled, Date dateCreated, double side1, double side2, double side3) {
        super(color, filled, dateCreated);
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public double getSide1() {
        return side1;
    }

    public void setSide1(double side1) {
        this.side1 = side1;
    }

    public double getSide2() {
        return side2;
    }

    public void setSide2(double side2) {
        this.side2 = side2;
    }

    public double getSide3() {
        return side3;
    }

    public void setSide3(double side3) {
        this.side3 = side3;
    }
    double getArea(){
        double s = getPerimeter()/2.0;
        return Math.sqrt(s*(s-side1)*(s-side2)*(s-side3));
    }
    double getPerimeter(){
        return side1 + side2 + side3;
    }

    @Override
    public String toString() {
        return "Triangle:" +
                "side1=" + side1 +
                " side2=" + side2 +
                " side3=" + side3 +
                ';';
    }
}

