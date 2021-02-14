//
// Copyright (c) 2021 bingxio. All rights reserved.
//

#include <iostream>

// define class
class User {
        // types of disclosure
    public:
        // field
        std::string username;
        std::string password;

        // method
        void set_address(std::string addr);

        // method
        std::string get_address();

        static const char *get_name() { return "<User>"; }
        // internal type
    private:
        // field
        std::string address;
};

// method implementation of class
void User::set_address(std::string addr) { this->address = std::move(addr); }

std::string User::get_address() { return this->address; }

class Box {
        //
    protected:
        int width;
};

class Box mediumBox;

class SmallBox : public Box {
    public:
        void set_width(int w);

        int get_width();
};

void SmallBox::set_width(int w) { this->width = w; }

int SmallBox::get_width() { return this->width; }

int main() {
    std::cout << "Hello World!!" << std::endl;

    auto user = new User;

    user->username = "July";
    user->password = "6347";
    user->set_address("CQ");

    std::cout << user->username << std::endl;
    std::cout << user->password << std::endl;
    std::cout << user->get_address() << std::endl;
    std::cout << user->get_name() << std::endl;

    class SmallBox box;

    box.set_width(34);
    std::cout << box.get_width() << std::endl;

    return 0;
}
