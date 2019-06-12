#include <iostream>

using namespace std;

/**
 * Base class Shape.
 */
class Shape {
    public:
        void setWidth(int w) {
            width = w;
        }

        void setHeight(int h) {
            height = h;
        }
    protected:
        int width;
        int height;
};

/**
 * Base class PaintCost.
 */
class PaintCost {
    public:
        int getCost(int area) {
            return area * 70;
        }
};

/**
 * Dervied class Rectangle inherit Shape and PaintCost.
 */
class Rectangle : public Shape, public PaintCost {
    public:
        int getArea() {
            return (width * height);
        }
};

int main() {

    Rectangle rect;

    rect.setWidth(5);
    rect.setHeight(7);

    int area = rect.getArea();

    cout << "total area: " << rect.getArea() << endl;

    cout << "total cost: $" << rect.getCost(area) << endl;

    return 0;
}
