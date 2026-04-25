//Write a C++ program to demonstrate the concept of function overloading by performing
//operations like calculating the area of a circle, rectangle, and triangle.
#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159;
// Function to calculate the area of a circle
double area(double radius) {
    return PI * radius * radius;
}
// Function to calculate the area of a rectangle
double area(double length, double width) {
    return length * width;
}
// Function to calculate the area of a triangle
double area(double base, float height) {
    return 0.5 * base * height;
}
int main() {
    double radius, length, width, base;
    float height;
    cout << "Enter radius of the circle: ";
    cin >> radius;
    cout << "Area of Circle: " << area(radius) << endl;
    cout << "Enter length and width of the rectangle: ";
    cin >> length >> width;
    cout << "Area of Rectangle: " << area(length, width) << endl;
    cout << "Enter base and height of the triangle: ";
    cin >> base >> height;
    cout << "Area of Triangle: " << area(base, height) << endl;
    return 0;
}