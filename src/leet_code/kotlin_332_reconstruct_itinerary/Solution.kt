package leet_code.kotlin_332_reconstruct_itinerary

import leet_code.kotlin_data.PostOrderDFS

class Solution : PostOrderDFS<String>() {

    private val graph = mutableMapOf<String, MutableList<String>>()

    fun findItinerary(tickets: List<List<String>>): List<String> {
        for (ticket in tickets) {
            graph[ticket[0]] = graph.getOrDefault(ticket[0], mutableListOf()).apply { add(ticket[1]) }
        }
        graph.values.forEach { it.sortDescending() }
        val result = mutableListOf<String>()
        solve("JFK", result::add)
        return result.reversed()
    }

    override fun children(input: String) = graph[input] ?: mutableListOf()

    override fun canVisit(node: String) = true
}
