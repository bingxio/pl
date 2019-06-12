#include <iostream>

using namespace std;

class Box {
    public:
        Box(int w);
        
        friend void printWidth(Box box);
    private:
        int width;
};

void printWidth(Box box) {
    cout << "width of box: " << box.width << endl;
}

Box::Box(int w): width(w) {}

int main() {
    
    Box box(122);
    
    printWidth(box);

    return 0;
}
