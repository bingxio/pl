#include <iostream>

using namespace std;

class Line {
    public:
        void setLength(int len);
        
        int getLength();
        
        /**
         * Ordinary constructive function.
         */
        Line(int len);
    
        /**
         * Copy constructor function.
         */
        Line(const Line &obj);
    
        /**
         * Destructive function.
         *
         * function must be declared with no arguments.
         */
        ~Line();
    private:
        int length;
        int *ptr;
    
        bool init;
};

/**
 * Initialization lists are used to initialize field;
 */
Line::Line(int len) : length(len), init(true) {
    cout << "-> Object is being created." << endl;
}

Line::Line(const Line &obj) {
    cout << "-> Object is being init." << endl;
    
    ptr = new int;
    
    *ptr = 3000;
    
    *obj.ptr = *ptr;
    
    cout << "-> Object private param ptr value: " << *obj.ptr << endl;
}

Line::~Line() {
    cout << "-> Object is being deleted." << endl;
    
    delete ptr;
}

void Line::setLength(int len) {
    length = len;
}

int Line::getLength() {
    return length;
}

int main() {

    Line line(10);
    
    cout << "length of line: " << line.getLength() << endl;
    
    line.setLength(20);
    
    cout << "length of line: " << line.getLength() << endl;
    
    /**
     * Copying variable, it will call copy function.
     */
    Line line2 = line;
    
    return 0;
}
