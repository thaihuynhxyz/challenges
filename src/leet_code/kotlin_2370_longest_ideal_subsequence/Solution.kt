package leet_code.kotlin_2370_longest_ideal_subsequence

import kotlin.math.*

class Solution {
    fun longestIdealString(s: String, k: Int): Int {
        val dp = Array(s.length) { IntArray(26) }
        s.map { it - 'a' }.forEachIndexed { index, c ->
            for (i in 0 until 26) {
                val previous = dp.getOrNull(index - 1)?.get(i) ?: 0
                if (abs(c - i) <= k) {
                    dp[index][c] = max(previous + 1, dp[index][c])
                }
                if (i != c) {
                    dp[index][i] = previous
                }
            }
        }
        return dp.last().max()
    }
}
