#include <iostream>
#include <vector>

using namespace std;

vector<string> P = {
    "子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥",
};

vector<string> K = {};

string input(const char *title) {
  cout << title;
  string in;
  cin >> in;
  return in;
}

int index_of(string g) {
  int p = 0;
  for (auto i = P.begin(); i != P.end(); i++, p++)
    if (*i == g) return p;
  return p;
}

vector<string> replace(int i) {
  vector<string> arr(12);
  for (auto j : K) {
    arr[i] = j;
    i++;
    if (i == 12) i = 0;
  }
  for (string p : arr) cout << p << " ";
  cout << endl;
  return arr;
}

int main() {
  for (int i = 0; i < 12; i++) cout << P[i] << i << " ";
  cout << endl;

  // string a = input("日支：");
  // string b = input("时支：");

  string p = input("");
  string a = "子", b = "酉";

  int i = index_of(P[stoi(p)]);
  vector<string> x = replace(i);

  const char *d = x[index_of(a)].c_str();
  const char *h = x[index_of(b)].c_str();

  printf("%10s日%s时\n", a.c_str(), b.c_str());
  printf("%10s%s%s\n", P[i].c_str(), d, h);
  return 0;
}
