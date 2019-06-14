#include <iostream>

using namespace std;

class User {
    public:
        string username;
	string password;
	
	User(string name, string pass);
};

User::User(string name, string pass): username(name), password(pass) {}

int main() {

    /**
     * Use new keyword to create new reference.
     *
     * if there are no parameters, don't write parentheses.
     *
     * User* a = new User;
     */
    User* a = new User("turaiiao", "12345678");
	
    cout << a -> username << endl;
    cout << a -> password << endl;

    /**
     * Must use delete keyword to release memory.
     */
    delete a;
	
    return 0;
}
