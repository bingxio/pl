package main

val accounts: MutableMap<Int, String> = mutableMapOf(1 to "turaiiao", 2 to "lily", 3 to "frank")

private fun updateAccountProfile(accountId: Int) {
    if (accounts.containsKey(accountId)) {
        println("Updating $accountId ...")
        accounts[accountId] = "updated"
    } else {
        println("Error: Typing to update to a non-existing account (id: $accountId)")
    }
}

private fun accountReport() {
    println("Account Report: ")

    accounts.forEach {
        k, v -> println("Id $k: credit $v")
    }
}

fun main() {

    accountReport()

    updateAccountProfile(2)

    accountReport()

    updateAccountProfile(1)

    accountReport()
}