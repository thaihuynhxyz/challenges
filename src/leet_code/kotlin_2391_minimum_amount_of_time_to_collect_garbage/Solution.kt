package leet_code.kotlin_2391_minimum_amount_of_time_to_collect_garbage

class Solution {
    fun garbageCollection(garbage: Array<String>, travel: IntArray): Int {
        var ans = 0
        var totalMinutes = 0
        val lastMinutes = HashMap<Char, Int>()
        garbage.forEachIndexed { index, s ->
            if (index > 0) {
                totalMinutes += travel[index - 1]
            }
            for (c in s.toSet()) {
                ans += (totalMinutes - (lastMinutes[c] ?: 0))
                lastMinutes[c] = totalMinutes
            }
            ans += s.length
        }
        return ans
    }
}