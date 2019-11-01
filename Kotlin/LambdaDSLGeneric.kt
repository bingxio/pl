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
  println(
    12.add(34)
  )
  val myArray = MyArray<Int>()
  for (i in 0..10 step 3) {
    myArray.addElement(i)
  }
  println(myArray.getElement(1))
}

private fun sum(term: (Int, Int) -> String, x: Int, y: Int): String = term(x, y)

private fun <T> Int.add(x: T): Int {
  if (x !is Int) {
    println("x is not a number !")
    return -1
  }
  return x.toInt() + this
}

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

private interface MyInterface<T> {
  fun addElement(element: T): T
  fun getElement(index: Int): T
}

class MyArray<T> : MyInterface<T> {
  var list = mutableListOf<T>()

  override fun addElement(element: T): T {
    list.add(element)
    return list.last()
  }

  override fun getElement(index: Int): T = list[index]
}
