void main() {
  test();
}

Future<bool> login(String username, String password) async => username.isNotEmpty && password.isNotEmpty;

test() async {
  await login('turaiiao', '12345678').then((data) {
    if (data) {
      print('Login successfully !');
    }
  });
}
