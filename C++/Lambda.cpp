#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    auto addition = [](int a, int b) -> int {
        if (a % 2 == 0) {
            return a + b;
        }
    }
    
    vector<int> a;
    
    a.reserve(20);
    
    for (int i = 0; i < 20; i ++) {
        a.push_back(i);
    }
}
