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
