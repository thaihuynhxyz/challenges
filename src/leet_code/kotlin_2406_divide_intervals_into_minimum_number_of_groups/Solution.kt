package leet_code.kotlin_2406_divide_intervals_into_minimum_number_of_groups

import kotlin.math.max
import kotlin.math.min

class Solution {
    fun minGroups(intervals: Array<IntArray>): Int {
        if (intervals.size == 1) return 1
        val starts = intervals.map { it[0] }.sorted()
        val ends = intervals.map { it[1] }.sorted()
        var ans = 0
        var endIdx = 0
        for (start in starts) {
            if (start > ends[endIdx]) {
                endIdx++
            } else {
                ans++
            }
        }
        return ans
    }

    fun minGroups1(intervals: Array<IntArray>): Int {
        var rS = intervals[0][0]
        var rE = intervals[0][1]
        for (i in 1 until intervals.size) {
            rS = min(rS, intervals[i][0])
            rE = max(rE, intervals[i][1])
        }

        val pointToCount = IntArray(rE + 2)
        for (interval in intervals) {
            pointToCount[interval[0]]++
            pointToCount[interval[1] + 1]--
        }

        var curInt = 0
        var maxInt = 0
        for (i in rS..rE) {
            curInt += pointToCount[i]
            maxInt = max(maxInt, curInt)
        }

        return maxInt
    }

    fun minGroups2(intervals: Array<IntArray>): Int {
        val m = mutableMapOf<Int, Int>()
        for (interval in intervals) {
            m[interval[0]] = m.getOrDefault(interval[0], 0) + 1
            m[interval[1] + 1] = m.getOrDefault(interval[1] + 1, 0) - 1
        }
        return m.toSortedMap().values.fold(0 to 0) { (cur, max), v -> (cur + v).let { it to max.coerceAtLeast(it) } }.second
    }
}
