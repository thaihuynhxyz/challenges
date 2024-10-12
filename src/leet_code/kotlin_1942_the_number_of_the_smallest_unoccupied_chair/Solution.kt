package leet_code.kotlin_1942_the_number_of_the_smallest_unoccupied_chair

import java.util.PriorityQueue

typealias NumIndex = Pair<Int, Int>

class Solution {
    fun smallestChair(times: Array<IntArray>, targetFriend: Int): Int {
        val leavingChairs = PriorityQueue<Int>()
        val arrivedChairs = mutableMapOf<Int, Int>()
        var maxChair = 0
        val arrivalTimes = mutableListOf<NumIndex>()
        val leavingTimes = mutableListOf<NumIndex>()
        times.forEachIndexed { index, it ->
            arrivalTimes.add(NumIndex(it[0], index))
            leavingTimes.add(NumIndex(it[1], index))
        }
        arrivalTimes.sortBy { it.first }
        leavingTimes.sortBy { it.first }
        while (arrivalTimes.isNotEmpty() || leavingTimes.isNotEmpty()) {
            if (arrivalTimes.first().first < leavingTimes.first().first) {
                val chairIndex = if (leavingChairs.isEmpty()) maxChair++ else leavingChairs.poll()
                if (arrivalTimes.first().second == targetFriend) return chairIndex
                arrivedChairs[arrivalTimes.removeFirst().second] = chairIndex
            } else {
                val leavingChair = arrivedChairs[leavingTimes.removeFirst().second]!!
                leavingChairs.add(leavingChair)
            }
        }
        throw IllegalStateException("Should not reach here")
    }
}
