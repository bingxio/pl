#include <iostream>

using namespace std;

class Line {
    public:
        void setLength(int len);
        
        int getLength();
        
        explicit Line(int len);
    private:
        int length;
};

Line:Line(int len) : length(len) {
    cout << "Object is being created, length = " << len << endl;
}

void setLength(int len) {
    length = len;
}

int getLength() {
    return length;
}

int main() {

    Line line(10);
    
    cout << "length of line: " << line.getLength() << endl;
    
    line.setLength(20);
    
    cout << "length of line: " << line.getLength() << endl;
    
    return 0;
}
