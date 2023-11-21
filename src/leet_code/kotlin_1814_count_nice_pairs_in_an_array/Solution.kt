package leet_code.kotlin_1814_count_nice_pairs_in_an_array

class Solution {
    fun countNicePairs(nums: IntArray): Int {
        val map = mutableMapOf<Int, Int>()
        val revMap = mutableMapOf<Int, Int>()
        var ans = 0L
        for (num in nums) {
            val rev = revMap.getOrPut(num) { rev(num) }
            ans += map.getOrDefault(num - rev, 0)
            map[num - rev] = map.getOrDefault(num - rev, 0) + 1
        }
        return (ans % 1000000007).toInt()
    }

    private fun rev(n: Int): Int {
        var rev = 0
        var num = n
        while (num > 0) {
            rev = rev * 10 + num % 10
            num /= 10
        }
        return rev
    }
}