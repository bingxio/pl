#include <iostream>
#include <string>

using namespace std;

int main() {
  char* username = (char *) malloc(64);
    
  cout << "Please input your name: ";
    
  /**
   * turaiiao
   */
  cin >> username;
    
  string a = username;
    
  /**
   * username = turaiiao, length = 8
   */
  cout << "username = " << username;
  cout << ", length = " << a.size() << endl;
    
  return 0;
}
