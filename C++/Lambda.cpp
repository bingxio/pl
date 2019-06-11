#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    auto addition = [](int a, int b) -> int {
        return a % b == 0 ? a : 0;
    }
    
    vector<int> numbers;
    
    numbers.reserve(10);
    
    for (int i = 10; i <= 20; i ++) {
        numbers.push_back(i);
    }
    
    for_each(numbers.begin(), numbers.end(), [addition](vector<int>::reference a) {
        int b = addition(a, 2);
        
        if (b != 0)
            cout << b << " ";
        else
            cout << "* " <<;
    });
}
