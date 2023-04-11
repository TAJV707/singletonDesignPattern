#ifndef SHAPES_H_
#define SHAPES_H_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define PI 3.14159265358979323846

//Abstract class for the shapes.
class Shape {
    public:
    virtual ~Shape() {}

    //Setters
    virtual void SetName(std::string name_) = 0;

    //Getters
    virtual std::string GetName() = 0;
    virtual double  GetWidth() const = 0;
    virtual double GetHeight() const = 0;

    //Returns the perimeter of the shape, if it a circle it returns the circumference 
    virtual double CalculatePerimeter() = 0;

    //Returns the area of the shape
    virtual double CalculateArea() const = 0;

    //scales the attributes of the shape by the given scalor
    virtual void Scale(double scalor) = 0;

    //personal name for each shape!
    std::string name;

};

class Rectangle : public Shape {
    public:
    //Rectangles take in a width and a height, and the constructor is polymorphic so you can choose 
    //To name your rectangle or not
    Rectangle(std::string name_, double width, double height);
    Rectangle(double width, double height);
    ~Rectangle() {}

    //Setters
    void SetName(std::string name_); 
    std::string GetName();

    //Getters
    double GetWidth() const; 
    double GetHeight() const; 

    //functions
    double CalculateArea() const; 
    double CalculatePerimeter(); 
    void Scale(double scalor); 
    
    //Operator Overloads
    Rectangle operator+(const Rectangle& other);
    Rectangle operator-(const Rectangle& other);
    Rectangle operator*(const Rectangle& other);
    Rectangle operator/(const Rectangle& other);

    private:
    double width;
    double height;

};

class Circle : public Shape {
    public:
    //Circle take in a radius, and the constructor is polymorphic so you can choose 
    //To name your circle or not
    Circle(std::string name_, double radius_);
    Circle(double radius_);
    ~Circle() {}

    //Setters
    void SetName(std::string name_);

    //Getters
    std::string GetName();
    
    //get width and height of a circle is just its diameter for both
    double GetWidth() const;
    double GetHeight() const;
    double GetRadius() const;
    
    //Functions
    double CalculatePerimeter();
    double CalculateArea() const;
    void Scale(double scalor);

    //Operator Overloads
    Circle operator+(const Circle& other);
    Circle operator-(const Circle& other);
    Circle operator*(const Circle& other);
    Circle operator/(const Circle& other);

    private:
    double radius;
};

class EquilateralTriangle : public Shape {
    public:
    //Triangle take in a base and height, and the constructor is polymorphic so you can choose 
    //To name your Triangle or not
    EquilateralTriangle(std::string name_, double base_);
    EquilateralTriangle(double base_);

    ~EquilateralTriangle() {}

    //setters
    void SetName(std::string name_);

    //getters
    std::string GetName();
    double GetWidth() const;
    double GetHeight() const;

    //functions
    double CalculateArea() const;
    double CalculatePerimeter();
    void Scale(double scalor);

    //operator overloads
    EquilateralTriangle operator+(const EquilateralTriangle& other);
    EquilateralTriangle operator-(const EquilateralTriangle& other);
    EquilateralTriangle operator*(const EquilateralTriangle& other);
    EquilateralTriangle operator/(const EquilateralTriangle& other);

    private:
    double base;
    double height;
    double radius;

};

#endif //SHAPES_H_