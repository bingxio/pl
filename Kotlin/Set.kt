package main

val openSusses: MutableSet<String> = mutableSetOf("uniqueDescr1", "uniqueDescr2", "uniqueDescr3")

fun addIssues(uniqueDesc: String): Boolean = openSusses.add(uniqueDesc)

fun getStatusLog(isAdded: Boolean): String = if (isAdded)
    "registered correctly."  else "marked as duplicate and rejected."

fun main() {

    val aNewIssues: String = "uniqueDescr4"

    val onIssuesAlreadyIn: String = "uniqueDescr2"

    println("Issues $aNewIssues ${ getStatusLog(addIssues(aNewIssues)) }")
    println("Issues $onIssuesAlreadyIn ${ getStatusLog(addIssues(onIssuesAlreadyIn)) }")
}