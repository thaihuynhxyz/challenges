package leet_code.kotlin_2477_minimum_fuel_cost_to_report_to_the_capital

import leet_code.kotlin_data.ParentDFS
import leet_code.kotlin_data.PreOrderDFS

class Solution : PreOrderDFS<Int>(), ParentDFS<Int> {
    override val parent = mutableMapOf<Int, Int>()

    private val graph = mutableMapOf<Int, List<Int>>()

    fun minimumFuelCost(roads: Array<IntArray>, seats: Int): Long {
        if (roads.isEmpty()) return 0
        for (road in roads) {
            graph[road[0]] = graph.getOrDefault(road[0], emptyList()) + road[1]
            graph[road[1]] = graph.getOrDefault(road[1], emptyList()) + road[0]
        }
        val stack = mutableListOf<Int>()
        val peopleFuel = Array(graph.size) { Pair(0, 0L) }
        solve(0) { stack.add(it) }
        for (i in stack.reversed()) {
            val p = parent[i] ?: continue
            val people = peopleFuel[p].first + peopleFuel[i].first + 1
            val fuel = peopleFuel[p].second + peopleFuel[i].second + (peopleFuel[i].first + seats) / seats
            peopleFuel[p] = people to fuel
        }
        return peopleFuel[0].second
    }

    override fun children(input: Int) = graph[input]?.toMutableList() ?: mutableListOf()
}