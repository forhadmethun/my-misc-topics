package assignment.first;

public class Rectangle extends GeometricObject {
    double width, height;
    Rectangle(){}
    Rectangle(double width,double height){
        this.width = width;
        this.height = height;
    }
    Rectangle(double width,double height, String color, boolean filled){
        this.width = width;
        this.height = height;
        this.color = color;
        this.filled = filled;

    }
    double getwidth(){
        return width;
    }
    void setWidth(double width){
        this.width = width;
    }
    double getHeight(){
        return height;
    }
    void setHeight(double height){
        this.height = height;
    }
    double getArea(){
        return height* width;
    }
    double getPerimeter(){
        return 2.0*(height + width);
    }

}
