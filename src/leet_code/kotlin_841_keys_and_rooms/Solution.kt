package leet_code.kotlin_841_keys_and_rooms

import leet_code.kotlin_data.PreOrderDFS

class Solution : PreOrderDFS<Int>() {

    private lateinit var graph: List<List<Int>>

    fun canVisitAllRooms(rooms: List<List<Int>>): Boolean {
        var sum = rooms.size * (rooms.size - 1) / 2
        graph = rooms
        solve(0) { sum -= it }
        return sum == 0
    }

    override fun children(input: Int) = graph[input].toMutableList()
}
