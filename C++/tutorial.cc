//
// Copyright (c) 2021 bingxio. All rights reserved.
//

// io
#include <iostream>
// date
#include <ctime>
// type
#include <typeinfo>
// vector
#include <vector>

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

// overload function
void sprint(int x) { std::cout << "Int: " << x << std::endl; }

void sprint(const char *x) { std::cout << "Str: " << x << std::endl; }

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

// overload operator
// must used for enumerated or class
class MyValue {
    public:
        int num;

//        there are no default parameters
        MyValue() = default;;

//        disable function
        MyValue(int a, int b, int c) = delete;

        explicit MyValue(int x) : num(x) {}

        MyValue operator+(const MyValue &rp) const {
            return MyValue(this->num + rp.num);
        }

//        destructor function
        ~MyValue() {
            std::cout << "DESTROY OF: "
                      << this->num << std::endl;
        };

        void output() const {
            std::cout << "MyValue -> "
                      << this->num << std::endl;
        }

//        static variable
        static int haha;

//        static function
//        only static variables and functions can be accessed
        static int get_num() { return ++haha; }
};

// initializing static variable
int MyValue::haha = 95;

// inline function
// at compile time, replace the place called with the
// body of this function
inline int max(int x, int y) { return x > y ? x : y; }

// polymorphic
class Shape {
    protected:
        int width;
        int height;
    public:
        explicit Shape(int x = 0, int y = 0) {
            this->width = x;
            this->height = y;
        }

//        abstract class and interface!!
//        the class must have virtual or pure virtual function

//        there are several different classes
//        all with functions of the same name but with
//        different implementations!!
        virtual int area() {
//            when you redefine a virtual function defined in the base class
//            in a derived class, you tell the compiler not to statically link to the function
            std::cout << "parent class area" << std::endl;
            return 0;
        }

//        pure virtual function
        virtual int some() = 0;

//        == != >= <= > <
        auto operator<=>(const Shape &shape) const {
//            equal
//            greater
//            less
//            equivalent
            return std::strong_ordering::equivalent;
        }
};

// polymorphic
class Rectangle : public Shape {
    public:
        Rectangle(int x, int y) : Shape(x, y) {}

        int area() override {
            std::cout << "rectangle class area" << std::endl;
            return this->width * this->height;
        }

//        pure virtual function
        int some() override { return 1; }
};

// polymorphic
class Triangle : public Shape {
    public:
        Triangle(int x, int y) : Shape(x, y) {}

//        override keyword
//        avoid the error of forgetting to rewrite virtual function
//        int derived class
        int area() override {
            std::cout << "triangle class area" << std::endl;
            return this->width * this->height;
        }

//        use override keyword
//        pure virtual function
        int some() override { return 2; }

//        if there is no such function in the base class,
//        or the function in the base class is not a virtual function,
//        the compiler will give an error message!!

//        int error() override { return -1; }
};

// exception
double division(int x, int y) {
    if (y == 0) {
        throw std::invalid_argument("division by zero arguments!!");
    }
    return double(x) / y;
}

// custom exception
struct MyException : public std::exception {
//        override virtual function form std::exception
    const char *what() const noexcept override { return "My Exception.."; }
};

// who?
void who() { throw MyException(); }

// namespace
namespace my_space {
//    variable in space
    std::string x = "C++";

//    function
    void func() {
        std::cout << "CALL AT MY_SPACE" << std::endl;
    }
//    container
    namespace container {
        void func() {
            std::cout << "CALL AT CONTAINER" << std::endl;
        }
    }
}

// function template
template<typename T>
inline T const &max(T const &a, T const &b) {
    if (a > b)
        return a;
    else
        return b;
}

// class template
template<class T>
class Stack {
    private:
//        collections
        std::vector<T> elems;
    public:
//        push to stack
        void push(T const &);

//        pop stack
        void pop();

//        return top of stack
        T top() const;

//        return the stack is empty
        bool empty() const { return elems.empty(); }
};

template<class T>
void Stack<T>::push(const T &elem) { this->elems.push_back(elem); }

template<class T>
void Stack<T>::pop() {
    if (this->empty()) {
        throw std::out_of_range("stack<>::pop(): empty stack!!");
    }
    elems.pop_back();
}

template<class T>
T Stack<T>::top() const {
    if (this->empty()) {
        throw std::out_of_range("stack<>::pop(): empty stack!!");
    }
    return elems.back();
}

// constant expression
constexpr int factorial(int n) {
//    constant expression of if statement
//    if constexpr (100 > -1) {
//        std::cout << "CALL" << std::endl;
//    }
    return n == 0 ? 1 : n * n;
}

// lambda
/**
 * [capture-list](params) mut(option) expr(option) attr(option) -> ret(option) { body }
 */
auto plus = [](int x, int y) -> int { return x + y; };

// NOLINT(bugprone-macro-parentheses)

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

//    overload function
    sprint(34);
    sprint("Hello C++!!");

//    overload operator
    MyValue lv(45);
    MyValue rv(39);

//    destroy here for anonymous function
    std::cout << (lv + rv).num << std::endl;
//    static
    std::cout << MyValue::haha << std::endl;
    std::cout << MyValue::get_num() << std::endl;

//    inline function
    std::cout << "MAX: " << max(4, 2) << std::endl;

//    pointer to class
    MyValue *value;

    value = &lv;
    value->output();

    value = &rv;
    value->output();

//    delete
    int *list = new int[3];

    list[0] = 35;
    list[1] = 56;
    list[2] = 24;

    for (int d = 0; d < 3; d++) std::cout << list[d] << std::endl;

    delete[] list;

//    polymorphic
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);

    shape = &rec;
    std::cout << shape->area() << std::endl;

    shape = &tri;
    std::cout << shape->area() << std::endl;

//    exception
    try {
        std::cout << division(50, 0) << std::endl;
//
    } catch (std::invalid_argument &e) {
//        output error message
        std::cout << e.what() << std::endl;
    }

    try {
        who();
    } catch (MyException &e) {
        std::cout << e.what() << std::endl;
    }
//    dynamic memory
    auto *dv = new double;

//    new not only allocates memory, it also creates objects.
    *dv = 4.6;
    std::cout << *dv << std::endl;

    delete dv;

    auto *sv = new int[20];

    for (int j = 0; j < 20; j++)
        sv[j] = j;

    for (int k = 0; k < 20; k++)
        std::cout << sv[k];
    std::cout << std::endl;

    delete[] sv;
//    namespace
    my_space::func();
    std::cout << my_space::x << std::endl;
    my_space::container::func();
//    using
    using namespace my_space;
//    definition alias
    using name = int;
//    definition type
    typedef int x_int;
//
    name jack = 45;
    const std::type_info &nameInfo = typeid(jack);

    std::cout << jack << " id -> " << nameInfo.name() << std::endl;
    std::cout << typeid(x_int).name() << std::endl;
//    template and generic
    std::cout << max(4, 6) << std::endl;
    std::cout << max(2.6, 2.3) << std::endl;
//    std::cout << max("34", "134") << std::endl;
//    template class
    try {
        Stack<int> intStack;
        Stack<std::string> stringStack;

        intStack.push(7);
        std::cout << intStack.top() << std::endl;

        stringStack.push("HELLO");
        std::cout << stringStack.top() << std::endl;

        intStack.pop();
        stringStack.pop();
//        exception
        intStack.pop();
    } catch (std::exception const &e) {
        std::cout << e.what() << std::endl;
    }
//    pretreatment
#define PI 3.1415926
#define MIN(a, b) ((a) < (b) ? a : b)
    std::cout << PI << std::endl;
    std::cout << MIN(5, 2) << std::endl;
//
#ifdef NULL
#define A (-1)
#endif
    std::cout << A << std::endl;

    std::cout << __LINE__ << std::endl;
    std::cout << __FILE__ << std::endl;
    std::cout << __DATE__ << std::endl;
    std::cout << __TIMESTAMP__ << std::endl;
    std::cout << __TIME__ << std::endl;
    std::cout << __VERSION__ << std::endl;

//    concatenation of literal quantities info strings
#define MKSTR(x) #x         // x to literal
#define CONCAT(x, y) x ## y // x + y to literal

    std::cout << MKSTR(HELLO C++ !!) << std::endl;

    int xy = 300;
    std::cout << "xy = " << CONCAT(x, y) << std::endl;
//    constant expression
    constexpr int k = 49 * 2 + 5;
    std::cout << factorial(5) << std::endl;
//    union type
    union numeric {
        short x;
        long y;
        double z;
    };
//    shared memory
    numeric numerics = {20}; // x: 20

    std::cout << numerics.x << std::endl; // 20
    std::cout << numerics.y << std::endl; // 20
    std::cout << numerics.z << std::endl; // 9.88131e-323
//    lambda
    struct Book {
        int id;
        std::string title;
        double price;
    };

    std::vector<Book> books;
    std::string target = "C++";

    auto res = std::count_if(
        books.begin(),
        books.end(),
        [&v= target](const Book &book) {
            return book.title.find(v) != std::string::npos;
        });
    std::cout << res << std::endl;
//    end
    return 0;
}
