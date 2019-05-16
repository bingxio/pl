
sealed class Sealed {

    object Sealed1 : Sealed()

    fun caller() {
        println("call")
    }
}

fun main() {
    val a = Sealed.Sealed1

    a.caller()
}