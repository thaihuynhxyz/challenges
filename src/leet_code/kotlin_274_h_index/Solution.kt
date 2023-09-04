package leet_code.kotlin_274_h_index

class Solution {
    fun hIndex(citations: IntArray): Int {
        val n = citations.size
        val buckets = IntArray(n + 1)
        for (c in citations) {
            if (c >= n) {
                buckets[n]++
            } else {
                buckets[c]++
            }
        }
        var count = 0
        for (i in n downTo 0) {
            count += buckets[i]
            if (count >= i) {
                return i
            }
        }
        return 0
    }
}