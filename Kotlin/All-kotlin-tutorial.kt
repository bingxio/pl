// Hello, nice to meet you !!
// This is kotlin language tutorial other have rust tutorial.
// You can star this project and read some language tutorial.
fun main() {
  // At variable definition we can use `val` or `var`.
  // The `var` keyword explain mutable and `val` is immutable.
  var a = 20
  // a is 21
  println(++a)

  // immutable variable.
  val b = 30

  println(b)

  // Of course we can type of regulations on variable name.
  // Normally not.
  val c: String = "Hello World"

  // We can define function use only one line.
  // And other lambda function is magic than Java !!
  fun sum(a: Int, b: Int): Int = a + b

  fun max(a: Int, b: Int): Int = if (a > b) a else b

  // Use string template with `$` operator to add two strings.
  println("sum = ${sum(23, 44)}")
  println("max = ${max(34, 22)}")
  // If we want splicing one field.
  println("a = $a")

  // The function parameter can be have default value.
  fun div(a: Int = 34, b: Int): Int {
    return a * b
  }

  println(div(33, 32))

  val d = 34
  val e = 22

  // The conditional expression is nothing special about it.
  if (d > e)
    println("a greater than b.")
  else if (d == e)
    println("a equal b.")
  else
    println("call else branch")

  // There is also the concept of null in kotlin,
  // If add `?` char after variable type explain it may be null !!
  fun parseInt(a: String): Int? {
    // We can return null value.
    return null
  }

  // Add `?` to define null value.
  val f: Int? = null

  // Null
  println(f)

  fun pointProduct(arg1: String, arg2: String) {
    // The variable x and y is always null value.
    // Because it call my function before definition.
    val x = parseInt(arg1)
    val y = parseInt(arg2)

    // Always true and both are null value.
    if (x != null && y != null)
      println(x * y)
    else
      println("'$arg1' or '$arg2' is not a number")
  }

  // If we want get a no nullable value..
  val x: Int? = 23
  // We can use `!!` operator to explain this value is no nullable !!
  // This is running well, if it it null the program will throw error.
  println(x!!)

  val y = "Kotlin"

  // Use `is` keyword to compare two expression.
  println(y is String)

  // Use generic paradigm to judge it is string type.
  fun <T> isStr(para: T): Boolean {
    return para is String
  }

  println(isStr("Hello"))
  println(isStr(12))

  // There is called the kotlin collection class to define a list.
  val items = listOf("apple", "banana", "kiwifruit")

  // Very easy to foreach it.
  for (item in items) {
    println(item)
  }

  // We can get index with `items.indices`
  for (index in items.indices) {
    println("item at $index is ${items[index]}")
  }

  var index = 0

  // The while statement is nothing special about it.
  // Be careful the index is mutable !!
  while (index < items.size) {
    println("item at $index is ${items[index]}")
    index++
  }

  // The when statement like switch or match in other language.
  // The `Any` is any Object like Java.
  fun describe(obj: Any): String = when (obj) {
    1 -> "One"
    "Hello" -> "Greeting"
    is Long -> "Long"
    !is String -> "Not a string"
    else -> "Unknown"
  }

  println(describe(13))
  println(describe(true))
  println(describe(23L))
  println(describe("Hello"))

  // Range
  for (i in 0..20)
    if (i % 2 == 0)
      println(i)

  // Over a progression:
  for (i in 0..10 step 2) {
    // 1 3 5 7 9
    println(i)
  }

  // And down to target with step.
  for (i in 9 downTo 0 step 2) {
    // 9 7 5 3 1
    println(i)
  }

  if ("banana" in items) {
    println("the items have banana item.")
  }

  // Print if it start with 'a' of item.
  items.forEach { it ->
    if (it.startsWith("a")) {
      println(it)
    }
  }

  // Define a class on kotlin.
  // More information to see https://kotlinlang.org
  class InitOrderDemo(val name: String) {

    // We can add multiply constructor in class.
    // If class have default constructor we need use `this` to call it.
    constructor(age: Int): this("test") {
      println("second constructor was called, age = $age")
    }

    // Called at class Initialization.
    init {
      println("name = $name")
    }

    // Class member variables.
    val property = "Property !!"

    // Class member function it it public.
    fun showName() {
      println(this.name)
    }
  }

  // We can leave out the `new` keyword to define class.
  // It is difference in Java.
  val orderDemo = InitOrderDemo("turaiiao")
  println(orderDemo.property)

  orderDemo.showName()

  // Second constructor was called.
  InitOrderDemo(17)

  // Use data class to define entity data like Java.
  data class User(val name: String, val pass: String) {
    var age: Int = 0
  }

  // The constructor must be init.
  val user = User("turaiiao", "12345678")
  // We can use block statement to define other fields.
  user.age = 17

  println(user)

  // Add interface with class and construct it.
  class Test(val age: Int) : Human {

    // Override function for interface defined.
    override fun eat() = println(
      if (age > 4) {
        "It can eating !!"
      } else {
        "Can not eating."
      }
    )
  }

  Test(12).eat()

  // The object is omnipotent.
  // Use field in object like data class.
  val point = object {
    var x: Int = 12
    var y: Int = 44
  }

  println(point.x + point.y)

  // Implement typealias it.
  val t: A<Int> = { it > 0 }

  // true
  println(t(23))
  // false
  println(t(-2))

  // Define a lambda expression with variable.
  // It have two parameter and it return a integer value.
  // Add two sum and return it.
  // We can appoint variable field after left brace.
  val sum: (Int, Int) -> Int = { x, y ->
    // The body can implement it.
    x + y
  }

  // Second mode we can let parameter in block.
  // Easy to understand.
  val mul = { x: Int, y: Int -> x * y }

  println(sum(34, 22))
  println(mul(44, 22))

  // This function has a function parameter.
  // It return a integer.
  // And function body was called it.
  fun foo(qux: () -> Int) = println(qux())

  // If it only have a function parameter.
  // We can use it like DSL mode.
  foo {
    println("called dsl function")
    // It return a integer so I give 666.
    666
  }

  val o: (Int) -> Int = { it + 2 }

  // Use function parameter like lambda expression.
  val sub: (Int, Int, (Int) -> Int) -> String = { a, b, term ->
    "${term(a + b)}"
  }

  // sub(term(12 + 44))
  println(sub(12, 44, o))

  val a1 = listOf("int", "string", "float", "boolean", "list")
  val a2 = listOf(1, 2, 3, 4, 5)

  // We can use `zip` keyword to zip two array like tuple data.
  // [(int, 1), (string, 2), (float, 3), (boolean, 4), (list, 5)]
  println(a1 zip a2)

  // Also we can custom design it.
  // [int == 1, string == 2, float == 3, boolean == 4, list == 5]
  println(a1.zip(a2) { x, y -> "$x == $y" })

  val numbers = listOf<Int>(1, -34, 223, -55, 3, 22, 12, -22)

  // Output it greater than zero in array.
  // [1, 223, 3, 22, 12]
  println(numbers.filter { x ->
    x > 0
  })

  // Mutable hasmap for kotlin language.
  val accounts: MutableMap<Int, String> = mutableMapOf(1 to "as", 2 to "er")

  println(accounts[1])
  // {1=as, 2=er}
  println(accounts)

  // Call Java native method !!
  System.out.println("This method was called by Java !!")
}

// Judge the number is greater than zero.
typealias A<T> = (T) -> Boolean

// The interface statement is nothing special about it.
// This object structure is default in all language.
interface Human {
  fun eat()
}
