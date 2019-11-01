fun main() {
  println("Hello Kotlin !")
  println(
    "${sum({ x, y -> (x + y).toString() }, 22, 66)} -> ${sum({ x, y -> (x + y).toString() }, 14, 89)}"
  )
  verticalLinearLayout {
    val a = 34
    println(a)
  }
  Person("turaiiao")()
}

private fun sum(term: (Int, Int) -> String, x: Int, y: Int): String = term(x, y)

private fun verticalLinearLayout(func: () -> Unit) {
  func()
}

class Person(private val name: String) {
  /**
   * Override function `invoke` for class.
   *
   * And I can use like call function with self of class.
   */
  operator fun invoke() {
    println("My name is $name")
  }
}
