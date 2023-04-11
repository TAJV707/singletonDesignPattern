#include "shapes.h"


int main() {
    std::cout << "Class Shapes extends to Rectangle, EquilateralTriangle, and Circle" << std::endl;

    EquilateralTriangle triangle1 = EquilateralTriangle("myTriange1", 11);
    EquilateralTriangle triangle2 = EquilateralTriangle("myTriange2", 50);

    Circle circle1 = Circle("myCircle1", 73);
    Circle circle2 = Circle("myCircle2", 30);

    Rectangle rectangle1 = Rectangle("myRectangle1", 41, 12);
    Rectangle rectangle2 = Rectangle("myRectangle2", 91, 14);

    std::cout << " " << std::endl;
    std::cout << "----- Testing Getters -----" << "\n" <<std::endl;

    std::cout << "Rectangle GetName(): " << rectangle1.GetName() << std::endl;
    std::cout << "Triangle GetName(): " << triangle1.GetName() << std::endl;    
    std::cout << "Circle GetName(): " << circle1.GetName() << "\n" << std::endl;

    std::cout << "Rectangle GetWidth(): " << rectangle1.GetWidth() << std::endl;
    std::cout << "Triangle GetWidth(): " << triangle1.GetWidth() << std::endl;    
    std::cout << "Circle GetWidth(): " << circle1.GetWidth() << "\n" << std::endl;

    std::cout << "Rectangle GetHeight(): " << rectangle1.GetHeight() << std::endl;
    std::cout << "Triangle GetHeight(): " << triangle1.GetHeight() << std::endl;    
    std::cout << "Circle GetHeight(): " << circle1.GetHeight() << "\n" <<std::endl;

    std::cout << "----- Testing Setters -----" << "\n" <<std::endl;
    
    triangle1.SetName("NewTriangleName");
    circle1.SetName("NewCircleName");
    rectangle1.SetName("NewRectanglenNme");

    std::cout << "Changing Rectangle name to NewRectangleName, calling GetName(): " << rectangle1.GetName() << std::endl;
    std::cout << "Changing Triangle name to NewTriangleName, calling GetName(): " << triangle1.GetName() << std::endl;
    std::cout << "Changing Circle name to NewCircleName, calling GetName(): " << circle1.GetName() << "\n" <<std::endl;

    std::cout << "----- Testing Functions -----" << "\n" <<std::endl;

    std::cout << "Rectangle CalculatePerimeter(): " << rectangle1.CalculatePerimeter() << std::endl;
    std::cout << "Triangle CalculatePerimeter(): " << triangle1.CalculatePerimeter() << std::endl;
    std::cout << "Circle CalculatePerimeter(): " << rectangle1.CalculatePerimeter() << "\n" << std::endl;

    std::cout << "Rectangle CalculateArea(): " << rectangle1.CalculateArea() << std::endl;
    std::cout << "Triangle CalculateArea(): " << triangle1.CalculateArea() << std::endl;
    std::cout << "Circle CalculateArea(): " << rectangle1.CalculateArea() << "\n" << std::endl;
    rectangle1.Scale(0.5);
    triangle1.Scale(0.5);
    circle1.Scale(0.5);

    std::cout << "Rectangle Scale(0.5): new width: " << rectangle1.GetWidth() << " new height: " << rectangle1.GetHeight() << std::endl;
    std::cout << "Triangle Scale(0.5): new width: " << triangle1.GetWidth() << " new height: " << triangle1.GetHeight() << std::endl;
    std::cout << "Circle Scale(0.5): new width: " << circle1.GetWidth() << " new height: " << circle1.GetHeight() << "\n " << std::endl;

    rectangle1.Scale(3);
    triangle1.Scale(3);
    circle1.Scale(3);
    std::cout << "Rectangle Scale(3): new width: " << rectangle1.GetWidth() << " new height: " << rectangle1.GetHeight() << std::endl;
    std::cout << "Triangle Scale(3): new width: " << triangle1.GetWidth() << " new height: " << triangle1.GetHeight() << std::endl;
    std::cout << "Circle Scale(3): new width: " << circle1.GetWidth() << " new height: " << circle1.GetHeight() << std::endl;

    std::cout << "----- Testing Operators -----" << "\n" <<std::endl;

    std::cout << "new Rectangle: width = 91, height = 14" << std::endl;
    std::cout << "new triangle: base = 50 height = 17" << std::endl;
    std::cout << "new Circle radius = 30\n" << std::endl;

    std::cout << "Rectangle + operator: new width: " << (rectangle1 + rectangle2).GetWidth() <<  " new Height: " << (rectangle1 + rectangle2).GetHeight() << std::endl;
    std::cout << "Triangle + operator: new width: " << (triangle1 + triangle2).GetWidth() <<  " new Height: " << (triangle1 + triangle2).GetHeight() << std::endl;
    std::cout << "Circle + operator: new width: " << (circle1 + circle2).GetWidth() <<  " new Height: " << (circle1 + circle2).GetHeight() << "\n" << std::endl;

    std::cout << "Rectangle - operator: new width: " << (rectangle1 - rectangle2).GetWidth() <<  " new Height: " << (rectangle1 - rectangle2).GetHeight() << std::endl;
    std::cout << "Triangle - operator: new width: " << (triangle1 - triangle2).GetWidth() <<  " new Height: " << (triangle1 - triangle2).GetHeight() << std::endl;
    std::cout << "Circle - operator: new width: " << (circle1 - circle2).GetWidth() <<  " new Height: " << (circle1 - circle2).GetHeight() << "\n" << std::endl;

    std::cout << "Rectangle * operator: new width: " << (rectangle1 * rectangle2).GetWidth() <<  " new Height: " << (rectangle1 * rectangle2).GetHeight() << std::endl;
    std::cout << "Triangle * operator: new width: " << (triangle1 * triangle2).GetWidth() <<  " new Height: " << (triangle1 * triangle2).GetHeight() << std::endl;
    std::cout << "Circle * operator: new width: " << (circle1 * circle2).GetWidth() <<  " new Height: " << (circle1 * circle2).GetHeight() << "\n" << std::endl;


    std::cout << "Rectangle / operator: new width: " << (rectangle1 / rectangle2).GetWidth() <<  " new Height: " << (rectangle1 / rectangle2).GetHeight() << std::endl;
    std::cout << "Triangle / operator: new width: " << (triangle1 / triangle2).GetWidth() <<  " new Height: " << (triangle1 / triangle2).GetHeight() << std::endl;
    std::cout << "Circle / operator: new width: " << (circle1 / circle2).GetWidth() <<  " new Height: " << (circle1 / circle2).GetHeight() << "\n" << std::endl;
}
