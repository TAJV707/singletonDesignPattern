#include "shapes.h"

//Rectangle
Rectangle::Rectangle(std::string name_, double width_, double height_) {
    width = width_;
    height = height_;
    name = name_;
}
Rectangle::Rectangle(double width_, double height_) {
    width = width_;
    height = height_;
    name = "";
}

void Rectangle::SetName(std::string name_){
    name = name_;
    return;
}

std::string Rectangle::GetName(){
    return name;
}

double Rectangle::CalculatePerimeter(){
    return (width + height) * 2;
}

void Rectangle::Scale(double scalor){
    width = width * scalor;
    height = height * scalor;
}

double Rectangle::GetWidth() const{
    return width;
}
double Rectangle::GetHeight() const {
    return height;
}

double Rectangle::CalculateArea() const {
    return width * height;
}
Rectangle Rectangle::operator+(const Rectangle&other){
    return Rectangle(this->width + other.GetWidth(), this->height + other.GetHeight());
} 
Rectangle Rectangle::operator-(const Rectangle& other){
    double tempWidth = this->width - other.GetWidth();
    double tempHeight = this->height - other.GetHeight();
    if(tempWidth < 0){
        tempWidth = 0;
    }
    if(tempHeight < 0){
        tempHeight = 0;
    }
    return Rectangle(tempWidth, tempHeight);
} 
Rectangle Rectangle::operator/(const Rectangle& other){
    return Rectangle(this->width / other.GetWidth(), this->height / other.GetHeight());
} 
Rectangle Rectangle::operator*(const Rectangle& other){
    return Rectangle(this->width * other.GetWidth(), this->height * other.GetHeight());
} 

//Circle

Circle::Circle(std::string name_, double radius_) {
    name = name_;
    radius = radius_;
}
Circle::Circle(double radius_) {
    name = "";
    radius = radius_;
}
void Circle::SetName(std::string name_){
    name = name_;
}

std::string Circle::GetName(){
    return name;
}
double Circle::GetRadius() const{
    return radius;
}

double Circle::CalculatePerimeter(){
    return 2 * PI * radius;
}

double Circle::CalculateArea() const {
    return PI * (radius * radius);
}
double Circle::GetWidth() const {
    return 2*radius;
}
double Circle::GetHeight() const {
    return 2*radius;
}
void Circle::Scale(double scalor){
    radius = radius * scalor;
}

Circle Circle::operator+(const Circle& other){
    return Circle(this->radius + other.GetRadius());
}
Circle Circle::operator-(const Circle& other){
    double tempRadius = this->radius - other.GetRadius();
    if(tempRadius < 0){
        tempRadius = 0;
    }
    return Circle(tempRadius);
}
Circle Circle::operator*(const Circle& other){
    return Circle(this->radius * other.GetRadius());
}
Circle Circle::operator/(const Circle& other){
    return Circle(this->radius / other.GetRadius());
}

//Triangle

EquilateralTriangle::EquilateralTriangle(std::string name_, double base_) {
    name = name_;
    base = base_;
    height = (sqrt(3)/2) * base;

}
EquilateralTriangle::EquilateralTriangle(double base_){
    name = "";
    base = base_;
    height = (sqrt(3)/2) * base;
    
}

void EquilateralTriangle::SetName(std::string name_){
    name = name_;
}

std::string EquilateralTriangle::GetName() {
    return name;
}

double EquilateralTriangle::CalculateArea() const {
    return (base * height) / 2;
}

double EquilateralTriangle::GetWidth() const {
    return base;
}

double EquilateralTriangle::GetHeight() const {
    return height;
}

double EquilateralTriangle::CalculatePerimeter() {
    return base * 3;
}

void EquilateralTriangle::Scale(double scalor){
    base = base * scalor;
    height = height * scalor;
}

EquilateralTriangle EquilateralTriangle::operator+(const EquilateralTriangle& other){
    return EquilateralTriangle(this->base + other.GetWidth());
}
EquilateralTriangle EquilateralTriangle::operator-(const EquilateralTriangle& other){
    double tempBase = this->base - other.GetWidth();
    if(tempBase < 0){
        tempBase = 0;
    }
   return EquilateralTriangle(tempBase);
}
EquilateralTriangle EquilateralTriangle::operator*(const EquilateralTriangle& other){
    return EquilateralTriangle(this->base * other.GetWidth());
}
EquilateralTriangle EquilateralTriangle::operator/(const EquilateralTriangle& other){
    return EquilateralTriangle(this->base / other.GetWidth());
}
