//
// Copyright (c) 2021 bingxio. All rights reserved.
//

// io
#include <iostream>
// date
#include <ctime>

// define class
class User {
//        types of disclosure
    public:
//        field
        std::string username;
        std::string password;

//        method
        void set_address(std::string addr);

//        method
        std::string get_address();

//        static state
        static const char *get_name() { return "<User>"; }
//        internal type
    private:
//        field
        std::string address;
};

// method implementation of class
void User::set_address(std::string addr) { this->address = std::move(addr); }

// members can by accessed to use private
std::string User::get_address() { return this->address; }

class Box {
//        protected member can be accessed by derived classes
    protected:
//        subclass can be accessed
        int width;
};

// the default inheritance is private
class SmallBox : Box {
    public:
//        set
        void set_width(int w);

//        get
        int get_width();
};

// implementation
void SmallBox::set_width(int w) { this->width = w; }

// can be accessed to use `width`
int SmallBox::get_width() { return this->width; }

// class
class A {
    public:
        int a = 1;
    private:
        int b = 2;
    protected:
        int c = 3;
};

/**
 * private members can only be accessed by members (in class)
 * and friends of class, not by derived classes.
 *
 * protected members can by accessed by derived classes.
 */

// public
class B : public A {
        B() : A() {
            std::cout << a << std::endl;
//            std::cout << b << std::endl;
            std::cout << c << std::endl;
        }
};

// private
class C : private A {
        C() : A() {
            std::cout << a << std::endl;
//            std::cout << b << std::endl;
            std::cout << c << std::endl;
        }
};

// protected
class D : protected A {
        D() : A() {
            std::cout << a << std::endl;
//            std::cout << b << std::endl;
            std::cout << c << std::endl;
        }
};

/**
 * structures can also be inherited be each other.
 *
 * the default inherited is public.
 */
struct Child : A {
    public:
        int x1;

        /**
         * explicit can only be used to modify class constructors
         * the decorated constructor cannot be called implicitly
         *
         * Child child = 4; // implicit 隐式调用
         * Child child(4);  // explicit 显式调用
         */
        explicit Child(int x) : A(), x1(x) {
            std::cout << "Child!!" << std::endl;
//            this->x1 = x;
        }
};

// implicit constructor!!
class Point {
    public:
        int x, y;

//        not use explicit keyword
        Point(int x = 0, int y = 0) : x(x), y(y) {
            std::cout << "x = " << x
                      << " y = " << y << std::endl;
        }
};

// quote and const of Point class
void display_point(const Point &p) {
    std::cout << "<Point x = " << p.x
              << " y = " << p.y << std::endl;
}

// int array
int arr[] = {2, 4, 2, 5};

// return the quote of array
int &get_quote(int i) { return arr[i]; }

// class of car
class Car {
//        private
    private:
//        private
        double price = 200000;

//        declare friend class
        friend class Driver;

//        declare friend function
        friend void show(Car car);
};

// friend function of car
// there is no need to add a qualifier
void show(Car car) {
    std::cout << "SHOW Car < " <<
              car.price << " >" << std::endl;
    car.price += 1;
}

// class of driver
class Driver {
    public:
        Car car;

//        constructor
        explicit Driver(Car car) : car(car) {}

//        change the value of a private member
        void modify() {
            std::cout << car.price << std::endl;

            car.price += 5000;

            std::cout << "MODIFY!!" << std::endl;
            std::cout << car.price << std::endl;
        }
};

// main function
int main() {
    std::cout << "Hello World!!" << std::endl;

//     on heap
    auto user = new User;

    user->username = "July";
    user->password = "6347";
    user->set_address("CQ");

    std::cout << user->username << std::endl;
    std::cout << user->password << std::endl;
    std::cout << user->get_address() << std::endl;
    std::cout << User::get_name() << std::endl;

    class SmallBox box;

    box.set_width(34);
    std::cout << box.get_width() << std::endl;

//     variable on stack
    int i = 30;
//     quote integer
    int &x = i;
    x++;
    std::cout << x << std::endl;

    for (auto item : arr) std::cout << item << std::endl;
    std::cout << get_quote(2)++ << std::endl;

//     implicit pointer
    get_quote(1) = 5;
    get_quote(3) = 9;

    for (auto item : arr) std::cout << item << std::endl;

//     current date
    const time_t now = time(nullptr);
    char *date = ctime(&now);

    std::cout << date << std::endl;

    tm *format_date = localtime(&now);
    std::cout << format_date->tm_sec << std::endl;

//    must not be called implicit
    struct Child child(34);

    std::cout << child.a << std::endl;
    std::cout << child.x1 << std::endl;

//    implicit constructor
    Point point = 4;
    display_point(point);
    display_point(76);
//    display_point(5, 3); arguments error!!

    Car car;
    Driver driver(car);

//    change the value of a private member
    driver.modify();
//    friend function of car
    show(car);
    show(driver.car);

    return 0;
}
