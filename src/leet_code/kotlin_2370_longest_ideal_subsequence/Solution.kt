package leet_code.kotlin_2370_longest_ideal_subsequence

import kotlin.math.*

class Solution {
    fun longestIdealString(s: String, k: Int): Int {
        return s.map { it - 'a' }.fold(
            Accumulator(
                MutableList(26) { 0 },
                Int.MAX_VALUE,
                Int.MIN_VALUE,
                0,
            )
        ) { acc, c ->
            val dp = acc.dp
            val minC = min(acc.minC, c)
            val maxC = max(acc.maxC, c)
            var m = 0
            for (i in max(minC, c - k)..min(maxC, c + k)) {
                m = max(m, dp[i])
            }
            dp[c] = m + 1
            Accumulator(dp, minC, maxC, max(acc.res, dp[c]))
        }.res
    }

    data class Accumulator(
        val dp: MutableList<Int>,
        val minC: Int,
        val maxC: Int,
        val res: Int,
    )
}
