#include <iostream>

class User {
    public:
        std::string username;
        std::string password;
        
        void setAddress(std::string addr);
        
        std::string getAddress();
    private:
        std::string address;
};

void User::setAddress(std::string addr) {
    address = addr;
}

std::string User::getAddress() {
    return address;
}

int main() {

    User a;
    
    a.username = "turaiiao";
    a.password = "12345678";
    
    a.setAddress("China");
    
    std::cout << "username = " << a.username << ", password = " << a.password << endl;
    std::cout << ", address = " << a.getAddress() << endl;
    
    return 0;
}
