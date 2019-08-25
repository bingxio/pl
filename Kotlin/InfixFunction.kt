package main

fun main() {
  infix fun Int.times(str: String) = str.repeat(this)
  println(2 times "Bye ")

  val pair = "Ferrari" to "Katrina"
  println(pair)

  infix fun String.onto(other: String) = Pair(this, other)

  val myPair = "McLaren" onto "Lucas"

  println(myPair)

  val sophia = Person("Sophia")
  val claudia = Person("Claudia")

  sophia likes claudia
}

class Person (private val name: String) {
  private val likedPeople = mutableListOf<Person>()

  infix fun likes(other: Person) {
    likedPeople.add(other)
  }
}