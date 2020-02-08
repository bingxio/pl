fun main() {
    Derived(34).also {
        it.type()
    }
//    Derived(56, "turaiiao")
    /**
     * 调用子类的内部类的方法
     */
    Third().Bar().call()
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
    constructor(x: Int, name: String): this() {
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