
interface UserModel {
  val prop: Int

  fun login (username: String, password: String): Boolean

  fun show () = println(prop)

  fun create () {}
}

interface People : UserModel {
  override val prop: Int get() = 50
}

class UserModelImp : UserModel, People {
  override val prop: Int get() = 20

  override fun login(username: String, password: String): Boolean {
    show().let {
      return !(username.isEmpty() || password.isEmpty())
    }
  }
}

fun main() {
  val userModelImp = UserModelImp()
  
  println(userModelImp.login("turaiiao", ""))
}