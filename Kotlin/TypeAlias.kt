
typealias MyComputer<T> = (T) -> Boolean

fun main() {
  val a: (Int) -> Boolean = { false }

  val b: MyComputer<String> = { it == "34" }

  println(a)
  println(b("12"))

  val plus: (Int, Int) -> String = { a: Int, b: Int -> "$a$b" }

  println(plus(23, 43))
}
