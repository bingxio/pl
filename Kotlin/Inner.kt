
class A {
  init {
    println("init A class")
  }

  inner class B {
    init {
      println("init B class")
    }
  }
}

fun main() {
  val a = A()

  a.B() // is a class.
}