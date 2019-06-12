#include <iostream>

using namespace std;

class Box {
    public:
        int width;
        
        Box operator + (const Box &b) {
            Box box;
            
            box.width = this -> width + b.width;
            
            return box;
        }
};

int main() {

    Box box1;
    Box box2;
    Box box3;
    
    box1.width = 12;
    box2.width = 34;
    
    box3 = box1 + box2;
    
    cout << "width of box 1: " << box1.width << endl;
    cout << "width of box 2: " << box2.width << endl;
    cout << "width of box 3: " << box3.width << endl;

    return 0;
}
