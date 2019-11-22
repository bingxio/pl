fun main() {
  // 使用伴生对象的方式去调用方法
  StringUtil.isEmpty("A")
  // 使用注解的方式去调用对象
  StringUtil.thisTodo
  // 使用新对象的方式去调用方法
  StringUtil().isStringInteger("234")

  SinglePattern.get()
  SinglePattern.get()
  SinglePattern.get()

  Test.FuckTest
}

class StringUtil {
  companion object {
    fun isEmpty(str: String): Boolean {
      return str == ""
    }
    @JvmStatic
    val thisTodo = "String Utils Class"
  }

  fun isStringInteger(str: String): Boolean {
    if (str.toIntOrNull() == null) {
      return false
    }
    return true
  }
}

/**
 * 使用伴生对象去创建单例模式
 *
 * -> 私有的构造方法表示不能被构造创建而只能使用伴生对象的方法
 */
class SinglePattern private constructor() {
  companion object {
    fun get(): SinglePattern {
      return Holder.instance
    }
  }

  private object Holder {
    val instance = SinglePattern()
  }
}

/**
 * 密闭类的定义只能在此文件内
 */
sealed class Test {
  object FuckTest
}
