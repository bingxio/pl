package main

fun main() {
  val a = listOf("int", "string", "float", "boolean", "list", "any")

  val b = listOf(1, 2, 3, 4, 5, 6)

  val resultPairs = a zip b
  val resultReduce = a.zip(b) { x, y -> "$x = $y"}

  println(resultPairs)
  println(resultReduce)
}