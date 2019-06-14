#include <iostream>

using namespace std;

class Point {
    double x, y;
    
    public:
        Point(double a, double b) {
            x = a;
            y = b;
        }
        
        /**
         * No meaningful definition of virtual function is given in the base class.
         *
         * Leave definition to derived class: { virtual double area() = 0; }
         *
         * Abstract class: 
         * 1.Class containing pure virtual functions are called abstract class.
         * 2.An abstract class has at least one pure imaginary function.
         * 3.An abstract class can only be derived as a base class.
         */
        virtual double area() {
            return 0;
        }
};

class Circle: public Point {
    double radius;
    
    public:
        Circle(double a, double b, double r): Point(a, b) {
            radius = r;
        }
        
        /**
         * The function of the same name in the derived class also automatically becomes a virtual function.
         */
        double area() {
            return radius * 2;
        }
};

int main() {
    
    Point a(1.2, 4.3);
    
    Circle b(1.6, 2.3, 4.5);
    
    Point* p1 = &b;
    Point& p2 = b;
    
    cout << p1 -> area() << endl;
    cout << p2.area() << endl;

    return 0;
}
