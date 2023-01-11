#include "json.h"

/* 年月获取节气 */
extern "C" const char* getSolarTerm(int year, int month) {
  /*

{
    solar: ["小寒", 5, 23, 5],
    middle: ["大寒", 20, 16, 29]
}
   */
  std::stringstream stream;
  stream << "{ solar: ["
         << "小寒,"
         << "5,"
         << "23,"
         << "5],";
  stream << "middle: ["
         << "大寒,"
         << "20,"
         << "16,"
         << "29] }";
  return stream.str().c_str();
}
