import 'dart:async';

showLogger(Function function) async => await Timer(Duration(seconds: 3), function);

void main() {
  print('Runnning on new thread...');
  showLogger(() {
    print('The thread was called end.');
  });
}
