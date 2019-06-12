#include <iostream>

using namespace std;

/**
 * Inline function:
 *
 * 1.Call the inline function to paste the expression directly !
 * 2.Cannot use loop statements.
 */
inline int max(int x, int y) {
    return x > y ? x : y;
}

int main() {

    cout << "max(1, 5): " << max(1, 5) << endl;
    cout << "max(4, 0): " << max(4, 0) << endl;
    
    return 0;
}
