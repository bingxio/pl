package main

val systemUsers: MutableList<Int> = mutableListOf(1, 2, 3)

val sudoers: List<Int> = systemUsers

private fun addSudoer(newUser: Int) = systemUsers.add(newUser)

private fun getSysSudoers(): List<Int> = sudoers

fun main() {
  addSudoer(4)

  println("Tot sudoers: ${ getSysSudoers().size }")

  getSysSudoers().forEach {
    i -> println("Some useful into on user $i")
  }
}