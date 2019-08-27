package main

val add: (Int, Int) -> Int = { x: Int, y: Int -> x + y }

val addWithLambdaExpr(x: Int, y: Int, add: (Int, Int) -> Int): Int = add(x, y)

val sub(): ((Int, Int) -> Int) {}

fun main() {}
