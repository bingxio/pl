fun main() {
    Derived(34).also {
        it.type()
    }
//    Derived(56, "turaiiao")
    /**
     * 调用子类的内部类的方法
     */
    Third().Bar().call()

    val a = mutableListOf(12, 34, 54, 67, 34)
    println(a)
    a.swap(0, 2)
    println(a)

    val user = User(1, "turaiiao")
    user.age = 23
    println(user)

    println(
        evaluate(
            BinaryExpr(
                Literal(34),
                "+",
                Literal(78)
            )
        )
    )

    outputItWithGenerics(23)
    outputItWithGenerics(3.2)

    sort(listOf(23, 55, 44, 22))
//    HashMap is not Comparable type
//    sort(listOf(HashMap<Int, Int>()))
}

/**
 * 函数加泛型
 */
fun <T> outputItWithGenerics(it: T) {
    if (it is Int) {
        println(it as Int)
    } else {
        println("我不知道参数的类型")
    }
}

/**
 * 泛型约定
 * 关键字 in 反向类型变异和 out 声名处的类型变异
 */
private fun <T : Comparable<T>> sort(item: List<T>) {
    item.forEach {
        if (it as Int > 25) {
            println(it)
        }
    }
}

/**
 * 密封类 常常使用于可能出现的所有条件判断
 * 枚举类只是一个值 而密封类里可以是很多子类
 */
sealed class Expr

data class Literal(val term: Int) : Expr()
data class BinaryExpr(val l: Expr, val op: String, val r: Expr) : Expr()

/**
 * 简单的诠释了密封类的使用
 */
private fun evaluate(expr: Expr): Int = when (expr) {
    is Literal -> expr.term
    is BinaryExpr -> {
        when (expr.op) {
            "+" -> evaluate(expr.l) + evaluate(expr.r)
            "-" -> evaluate(expr.l) - evaluate(expr.r)
            else -> -1
        }
    }
}

/**
 * 数据类
 */
data class User(val id: Int, val name: String) {
    /**
     * 可选参数 它不会被默认输出
     */
    var age: Int = 18
}

/**
 * 扩展函数
 */
private fun <T> MutableList<T>.swap(a: Int, b: Int) {
    val x = this[a]
    this[a] = this[b]
    this[b] = x
}

/**
 * 超类
 */
open class Base() {
    /**
     * 可被重写的属性
     */
    open val x = -1

    /**
     * 次构造器
     */
    constructor(x: Int, name: String) : this() {
        println("x = $x name = $name")
    }

    /**
     * 公共方法
     */
    fun show() = println("Call !!")

    /**
     * 允许被重写的方法
     */
    open fun type() = println("Type base")

    /**
     * 用于子类中内部类调用
     */
    fun test() {
        println("Called on inner class")
    }
}

/**
 * 继承自超类
 */
open class Derived(x: Int) : Base() {
    /**
     * 重写超类的属性 没有修饰为最终的
     */
    override val x: Int = 1

    /**
     * 实例化类
     */
    init {
        super.show()
    }

    /**
     * 重写超类的方法
     * 如果父类是超类 那么子类也可以重写父类的所有方法 可以使用最终修饰符
     */
    final override fun type() = println("Type derived")
}

class Third : Derived(-1) {
    /**
     * 此处可以重写父类的属性
     */
    override val x: Int get() = 3
    /**
     * 这里不能被重写 因为它被修饰为最终的
     */
//    override fun type() {
//        super.type()
//    }
    /**
     * 内部类
     */
    inner class Bar {
        /**
         * 内部类方法
         */
        fun call() {
            // 使用父类修饰符 + @ 可调用父类的属性或方法
            super@Third.test()
        }
    }
}