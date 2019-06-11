#include <iostream>
#include <utility>

class User {
    public:
        std::string username;
        std::string password;
        
        void setAddress(std::string addr);
        
        std::string getAddress();
    private:
        std::string address;
};

class Box {
    protected:
        int width;
};

class SmallBox : public Box {
    public:
        void setWidth(int w);
    
        int getWidth();
};

void User::setAddress(std::string addr) {
    address = std::move(addr);
}

std::string User::getAddress() {
    return address;
}

void SmallBox::setWidth(int w) {
    width = w;
}

int SmallBox::getWidth() {
    return width;
}

int main(int argc, char** argv) {

    User a;
    
    a.username = "turaiiao";
    a.password = "12345678";
    
    a.setAddress("China");
    
    std::cout << "username = " << a.username << ", password = " << a.password << std::endl;
    std::cout << ", address = " << a.getAddress() << std::endl;
    
    SmallBox b;
    
    b.setWidth(20);
    
    std::cout << "small box width is " << b.getWidth() << std::endl;
    
    return 0;
}
