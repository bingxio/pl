import 'dart:convert';

main() async {
  var x = 56;
  
  String str = 'Hello,';

  print('$str Dart !');


  var arr = [];

  for (var i = 0; i < 20; i ++)
    arr.add(i);

  print('arr len = ${arr.length}');

  for (var i in arr) {
    if (i % 2 == 0) {
      print(i);
    }
  }
  
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
