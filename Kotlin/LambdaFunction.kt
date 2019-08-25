
fun foo(bar: Int = 0, baz: Int = 1, qux: () -> Unit) {}

fun foo(vararg strings: String) { strings.forEach { println(it) } }

private val repeatFun: String.(Int) -> String = { "666" }

private fun runTransformation (f: (String, Int) -> String): String = f("hello", 3)

private val stringPlus: (String, String) -> String = String::plus
private val intPlus: (Int, Int) -> Int = Int::plus

private val plus = { x: Int, y: Int -> x + y }
private val minus: (Int, Int) -> Int = { x, y -> x - y }

val sum = fun Int.(other: Int): Int = this + other

fun main() {
  foo(1) { println("hello") }
  foo(qux = { println("hello") })
  foo { println("hello") }

  foo(strings = *arrayOf("a", "b", "c"))

  val items = listOf(1, 2, 3, 4, 5, 6)

  items.fold(0, { acc: Int, i: Int ->
    print("acc = $acc, i = $i, ")
    println("result = ${acc + i}")
                 
    acc + i
  })

  val a = { i: Int -> i + 1 }

  println(a(2))

  val b: (Int, Int) -> Boolean = { x: Int, y: Int -> x > y }

  @Suppress("NAME_SHADOWING") val c: (List<Any>) -> List<Any> = { i: List<Any> ->
    val items = ArrayList<Any>()

    for (v in 5 downTo 0) {
      items.add(i[v])
    }

    items
  }

  println(b(2, 6))
  println(c(items))

  items.filter { it > 2 }.forEach { println(it) }

  println(runTransformation(repeatFun))
  println(stringPlus("hello ", "world"))

  println(sum(23, 34))
}

var o: (Int) -> Int = { it + 2 }

fun sum(a: Int, b: Int, term: (Int) -> Int): String = "${term(a + b)}"

sum(1, 2, o) // 5

