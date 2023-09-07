package leet_code.kotlin_841_keys_and_rooms

import leet_code.kotlin_data.DSF

class Solution {
    fun canVisitAllRooms(rooms: List<List<Int>>): Boolean {
        var sum = rooms.size * (rooms.size - 1) / 2
        RoomsDSF(rooms).solve(0) { sum -= it }
        return sum == 0
    }
}

class RoomsDSF(private val rooms: List<List<Int>>) : DSF<Int>() {
    override fun children(input: Int) = rooms[input]
}
