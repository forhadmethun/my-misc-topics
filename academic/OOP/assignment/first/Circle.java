package assignment.first;

public class Circle extends GeometricObject {
    double radius;
    public Circle() {
    }


    public Circle(double radius, String color, boolean filled) {
        this.radius = radius;
        this.color = color;
        this.filled = filled;
    }


    public Circle( double radius) {
        this.radius = radius;
    }
    double getRadius(){
        return radius;
    }
    void setRadius(double radius){
        this.radius = radius;
    }
    double getArea(){
        return Math.PI*radius*radius;
    }
    double getPerimeter(){
        return 2.0*Math.PI*radius;
    }
    double getDiameter(){
        return 2.0*radius;
    }
    void printCircle(){

    }

}
