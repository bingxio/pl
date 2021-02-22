#include <iostream>
#include <map>
#include <vector>

class Foo {
  public:
    std::string str;
    
    Foo(std::string str): str(str) {}
};

int main() {
  std::vector<Foo> elem = { Foo("643"), Foo("753"), Foo("133") };
  std::map<Foo *, int> amap;
  
  int x = -1;
  
  while (x ++ < 2) {
    // Foo f = elem.at(x);
    // amap.insert(std::make_pair(&f, x + 1));
    amap.insert(std::make_pair(&elem.at(x), x + 1));
    std::cout << amap.size() << std::endl;
  }
  
  for (auto &i : amap) {
    std::cout << i.first->str << std::endl;
  }
  
  return 0;
}
