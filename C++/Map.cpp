#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

    vector<int> a = vector<int>();
    
    for (int i = 0; i < 5; i ++)
        a.emplace_back(i);
        
    for (vector<int>::iterator i = a.begin(); i != a.end(); i ++)
        cout << *i << " ";
    cout << endl;
    
    map<string, int> users = map<string, int>();
    
    users.insert(pair<string, int>("turaiiao", 10010));
    users.insert(pair<string, int>("helloiao", 34023));
    
    map<string, int>::iterator finded = users.find("turaiiao");
    
    if (finded != users.end())
        cout << finded->first << " " << finded->second << endl;
    else
        cout << "do not find" << endl;

    return 0;
}
