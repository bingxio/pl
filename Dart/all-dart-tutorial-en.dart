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

  // Declare a new object without `new` keyword after 2.5 version.
  var user = User();
  // This method is to setter age member variable.
  user.age = 45;
  // Get member variable and output.
  print('${user.age} -> ${user.ageString}');

  int add(int a, int b) => a + b;
  // At this function we used alias parameter.
  // { <aliasParameters...> }
  int sub(int a, int b, {String msg, bool reverse}) {
    print(msg);

    if (reverse) {
      return b - a;
    }
    return a - b;
  }
  // Optinal parameter.
  // [ <optinalParameters...> ]
  alert(String msg, [int count]) {
    // If not declare optional parameter it will be null.
    // Called will throw some exception.
    if (count != null) {
      for (var i = 0; i < count; i ++)
        print(msg);
    }
  }

  print(add(45, 66));
  // Use name of parameter to appoint alias parameter.
  // We must use alias parameter and unknown can be arbitrary.
  print(sub(65, 23, reverse: false, msg: 'Testing...'));

  alert('HelloWorld');
  // The optional parameter must One-to-one correspondence.
  alert('DART !', 5);

  await login('turaiiao', '12345678').then((data) {
    if (!(data as Map<String, dynamic>).containsValue('message')) {
      print(json.encode(data));
    }
  });
}
// Declare a new class object.
class User {
  // Member variable.
  // Default to setter method.
  int age;
  // Getter method.
  String get ageString => 'Age = ${this.age}';
  // Constructor function.
  User(/** construction variable can be here. */) {
    print("Object will be created...");
  }
  // Must be one construction method !
  // User(int age) {
  // }
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
