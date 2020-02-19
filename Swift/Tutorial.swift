//
//  main.swift
//  Demo
//
//  Created by 丙寅乙 on 2020/2/19.
//  Copyright © 2020 turaiiao. All rights reserved.
//

import Foundation

print("Hello, World!")

// mutable
var myVariable = 45
// immutable
let myConstant = 33
//
myVariable = 12
// Explain this variable is immutable because its used `let` to allocated.
// myConstant = 99
print(myVariable, myConstant) // The parameters of function is multiple.
// Both are double type of variable.
let implicitDouble = 50.0
let explicitDouble: Double = 50
// String template.
let x = 45
print("The value of x is \(x)")
// print("The value of x is" + a)
print("The value of x is " + String(x))
let longerLiteral = """

    My name is turaiiao,

    I am from China ChongQing\n
"""
print(longerLiteral)
// Array
var shoppingList = ["catfish", "water", "tulips"]
shoppingList[1] = "apple"
shoppingList.append("orange")
print(shoppingList)
// Empty Array
// var someArray = [SomeType](repeating: InitialValue, count: NumbeOfElements)
let emptyArr: [Int] = [Int](repeating: 12, count: 5)
let emptyDic = [String : Int]()
print(emptyArr.count, emptyDic.count, shoppingList.count)
// Branch
for v in shoppingList {
    print("The count of character is \(v.count) -> \(v)")
    if v.count == 6 {
        print("")
    }
}
//
var optionalString: String? = "Swift !"
var gretter = "Hello, "
// And swift have Optional Value both of other programmming language.
// The if statement can be used here with optinal.
if let name = optionalString {
    // Allocated a new variaible of `name` and next can be use optinal variable.
    gretter += name
}
print(gretter)
//
let nickName: String? = nil
let fullName: String = "turaiiao."
// Suffix operator !!
// It will found not nil value to use.
let informatGreeting = "Hi, \(nickName ?? fullName)"
print(informatGreeting)
//
switch fullName {
case "franke":
    break
case "turaiiao.":
    print("OK")
// Pattern matching
//
case let x where x.hasSuffix("end"):
    print("Hello \(x)")
default:
    print("Default branch...")
}
//
let interestingNumbers = [
    "Prime": [2, 3, 5, 7, 11, 13],
    "Fibonacci": [1, 1, 2, 3, 5, 8],
    "Square": [1, 4, 9, 16, 25]
];
var largets = 0
// Returned the max of numbers.
//
for (_, numbers) in interestingNumbers {
    for number in numbers {
        if number > largets {
            largets = number
        }
    }
}
print("Max = \(largets)")
// Loop
//
var n = 2
while n < 100 {
    n += 2
}
print("N = \(n)")

var m = 2
// The `repeat` keyword is like to `do` while statement.
//
repeat {
    m *= 2
} while m < 100
print("M = \(m)")
//
var total = 0
// Range
//
for i in 0..<5 {
    total += i
}
print("Total = \(total)")

// If the param use `_` starter to explain its can not appoint variable name.
//
func greet(_ person: String, day: String) -> String {
    return "Hello \(person), today is \(day)."
}
// The first param is not used lable to call.
//
print(greet("Bob", day: "Tuesday"))

//
func calculateStatistics(scores: [Int]) -> (min: Int, max: Int, sum: Int) {
    var min = scores[0]
    var max = scores[0]
    
    var sum = 0
    
    for score in scores {
        if score > max {
            max = score
        } else if score < min {
            min = score
        }
        sum += score
    }
    
    return (min, max, sum)
}

//
let statistics = calculateStatistics(scores: [5, 3, 100, 3, 9])
print(statistics.sum)
// There is used as tuple type.
//
print("SUM = \(statistics.2)")

// Closure
//
func returnFifteen() -> Int {
    var y = 10
    func add() {
        y += 5
    }
    add()
    return y
}
print(returnFifteen())

// Return Function.
//
func makeIncrementer() -> ((Int) -> Int) {
    func addOne(number: Int) -> Int {
        return 1 + number
    }
    return addOne
}
print(makeIncrementer()(7))

// Function Parameter.
//
func hasAnyMatches(list: [Int], condition: (Int) -> Bool) -> Bool {
    for item in list {
        if condition(item) {
            return true
        }
    }
    return false
}

func lessThanTen(number: Int) -> Bool {
    return number < 10
}

var numbers = [20, 19, 7, 12]
print(hasAnyMatches(list: numbers, condition: lessThanTen))

// Functional Programming.
//
let _ = numbers.map({ (number: Int) -> Int in return 3 * number })
let mappedNumbers = numbers.map({ number in 3 * number })
print(mappedNumbers)

// Object
//
class NamedShape {
    var numberOfSides = 0
    var name: String
    
    init(name: String) {
        self.name = name
    }
    
    func simpleDescription() -> String {
        return "A shape with \(numberOfSides) sides."
    }
}

// var shape = Shape()
// shape.numberOfSides = 7
// var shapeDescription = shape.simpleDescription()

class Square: NamedShape {
    var sideLength: Double
    
    init(sideLength: Double, name: String) {
        self.sideLength = sideLength
        super.init(name: name)
        numberOfSides = 4
    }
    
    func area() -> Double {
        return sideLength * sideLength
    }
    
    override func simpleDescription() -> String {
        return "A shape with sides of length \(sideLength)"
    }
}

let test = Square(sideLength: 5.2, name: "My test square")
print(test.area())
print(test.simpleDescription())

class EquilateralTriangle: NamedShape {
    var sideLength: Double = 0.0
    
    init(sideLength: Double, name: String) {
        self.sideLength = sideLength
        super.init(name: name)
        numberOfSides = 3
    }
    
    var perimeter: Double {
        get {
            return 3.0 * sideLength
        }
        set {
            sideLength = newValue / 3.0
        }
    }
    
    override func simpleDescription() -> String {
        return "An equilateral triangle with sides of length \(sideLength)."
    }
}

var triangle = EquilateralTriangle(sideLength: 3.1, name: "A triangle")
print(triangle.perimeter)
triangle.perimeter = 9.9
print(triangle.sideLength)
