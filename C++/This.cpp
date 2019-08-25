#include <iostream>

using namespace std;

class User {
  public:
    static int money;
    
    User(string name = "turaiiao", string pass = "12345678") {
      username = name;
      password = pass;      
      money ++;
    }
        
    bool compare(User user);
  private:
    string username;
    string password;
};

int User::money = 10000;

bool User::compare(User user) {
  return this->username == user.username;
}

int main() {  
  User user1;
  User user2("frank", "87654321");
    
  if (user1.compare(user2)) {
    cout << "User name of User 1 is the same as User 2." << endl;
  } else {
    cout << "User name of User 1 is different from User 2." << endl;
  }
    
  cout << User::money << endl;
    
  return 0;
}
