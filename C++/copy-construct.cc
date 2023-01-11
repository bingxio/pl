#include <iostream>
#include <vector>

class foo {
 private:
  int *ptr = nullptr;

 public:
  foo(int);

  /* copy constructor */
  foo(const foo &);

  ~foo() {
    /* if copy
      attempting double-free */
    if (this->ptr != nullptr) delete ptr;
  }
};

foo::foo(int num) {
  this->ptr = new int;
  *(this->ptr) = num;
  std::cout << "init " << *(this->ptr) << std::endl;
}

foo::foo(const foo &f) {
  std::cout << "capy" << std::endl;
  this->ptr = f.ptr;
}

int main() {
  std::vector<foo> item;
  // get memory, if length > mem,
  // it will copy construct
  item.reserve(12);

  for (int i = 1; i <= 12; i++) {
    // foo p = foo(i);
    // item.push_back(i);  // quote or copy
    item.emplace_back(i);  // new
  }
  return 0;
}
