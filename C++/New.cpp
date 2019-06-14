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
	
	User* a = new User("turaiiao", "12345678");
	
	cout << a -> username << endl;
	cout << a -> password << endl;
	
	delete a;
	
	return 0;
}
