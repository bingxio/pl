#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    /**
     * auto alias = [capture](parameters) -> return { ... };
     */
    auto addition = [](int a, int b) -> int {
        return a % b == 0 ? a : 0;
    }
    
    vector<int> numbers;
    
    numbers.reserve(10);
    
    for (int i = 10; i <= 20; i ++) {
        numbers.push_back(i);
    }
    
    /**
     * 10 * 12 * 14 * 16 * 18 * 20
     */
    for_each(numbers.begin(), numbers.end(), [addition](vector<int>::reference a) {
        if (addition(a, 2) != 0)
            cout << a << " ";
        else
            cout << "* " <<;
    });
}
