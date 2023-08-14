package leet_code.find_kth_largest

class FindKthLargest {
    fun findKthLargest(nums: IntArray, k: Int): Int {
        var min = Int.MAX_VALUE
        var max = Int.MIN_VALUE
        for (num in nums) {
            min = min.coerceAtMost(num)
            max = max.coerceAtLeast(num)
        }
        val dp = IntArray(max - min + 1)
        for (num in nums) {
            dp[num - min]++
        }
        var count = 0
        for (i in dp.indices.reversed()) {
            count += dp[i]
            if (count >= k) {
                return i + min
            }
        }
        return -1
    }
}
