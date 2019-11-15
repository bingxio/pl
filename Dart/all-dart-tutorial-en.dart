// The tutorial for Dart programming language write at Nov 15 2019.

// import <path> | as <alias> | show <field...> ;
// The `dart:` is standard library in Dart.
import 'dart:convert';

// If the function not have return type I can ignore it.
// The `main` function is can be asynchronous.
main() async {
  // I can use `var` keyword to automatic judgment type of variable.
  var x = 56;
  // And explain the type of variable.
  // The only one or double colon fine assign a string literal.
  String str = 'Hello,';
  // Output string with template.
  print('$str Dart !');

  // Assign a empty list.
  var arr = [];
  // First kind to use `for` loop statement.
  // for (<initExpr>; <CondExpr>; <UpExpr>) {}
  for (var i = 0; i < 20; i ++)
    arr.add(i);
  // 20
  // Use `${expr}` to get expression string literal.
  // The `length` method is standrad libray for array list std.
  print('arr len = ${arr.length}');
  // Second kind to use `for` loop statement.
  // for (var <ident> in <arr>) {}
  for (var i in arr) {
    // Traversing the value of an array.
    if (i % 2 == 0) {
      print(i);
    }
  }
  // And use lambda expression.
  arr.forEach((value) {
    print('value = $value');
  });

  var user = User();

  await login('turaiiao', '12345678').then((data) {
    if (!(data as Map<String, dynamic>).containsValue('message')) {
      print(json.encode(data));
    }
  });
}

class User {
  int age;

  set Age(int age) => age = age;

  String get ageString => '${this.age}';
}

Future<dynamic> login(String username, String password) async {
  if (username.isEmpty || password.isEmpty) {
    return {
      'message': 'BadRequest'
    };
  }
  return {
    'username': username,
    'password': password
  };
}
