package leet_code.kotlin_209_minimum_size_subarray_sum

class Solution {
    fun minSubArrayLen(target: Int, nums: IntArray): Int {
        var min = Int.MAX_VALUE
        var sum = 0
        var start = 0
        for (end in nums.indices) {
            sum += nums[end]
            while (sum >= target) {
                min = min.coerceAtMost(end - start + 1)
                sum -= nums[start++]
            }
        }
        return if (min == Int.MAX_VALUE) 0 else min
    }
}