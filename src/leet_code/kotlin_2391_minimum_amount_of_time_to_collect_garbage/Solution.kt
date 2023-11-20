package leet_code.kotlin_2391_minimum_amount_of_time_to_collect_garbage

class Solution {
    fun garbageCollection(garbage: Array<String>, travel: IntArray): Int {
        val lastMinutes = IntArray(3)
        var ans = 0
        var totalMinutes = 0
        garbage.forEachIndexed { index, s ->
            if (index > 0) {
                totalMinutes += travel[index - 1]
            }
            for (c in s.toSet()) {
                val garbageIndex = when (c) {
                    'M' -> 0
                    'P' -> 1
                    else -> 2
                }
                val minutes = totalMinutes - lastMinutes[garbageIndex]
                lastMinutes[garbageIndex] = totalMinutes
                ans += minutes
            }
            ans += s.length
        }
        return ans
    }
}