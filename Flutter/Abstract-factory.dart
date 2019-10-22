import 'dart:math';

abstract class Shape {
  num get area;
  
  factory Shape(String type) {
    if (type == 'circle') {
      return Circle(2);
    }
    throw 'Can\'t create $type';
  }
}

class Circle implements Shape {
  final num radius;
  
  Circle(this.radius);
  
  num get area => pi * pow(radius, 2);
}

void main() {
  print('Hello, Dart !!');
  
  final circle = Shape('circle');
  
  print(circle.area);
}
