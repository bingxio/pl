#include <iostream>

using namespace std;

class Male {
    public:
    
        /**
         * If use explicit keyword, represents that this function is an explicit transformation.
         */
        explicit Male(int a);
        
        ~Male();
};

Male::Male(int a) {
    cout << "object is created." << endl;
}

Male::~Male() {
    cout << "object is deleted." << endl;
}

void fun(Male* male) {
    cout << "call fun" << endl;
}

int main() {

    Male* a = new Male("turaiiao");

    /**
     * If it's not an explicit conversion, this parameter can be passed as an integer.
     */
    fun(a);
    
    delete a;
    
    return 0;
}
