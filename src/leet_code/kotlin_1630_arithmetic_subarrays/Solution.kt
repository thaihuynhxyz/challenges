package leet_code.kotlin_1630_arithmetic_subarrays

class Solution {
    fun checkArithmeticSubarrays(nums: IntArray, l: IntArray, r: IntArray): List<Boolean> {
        return l.mapIndexed { index, i -> arithmetic(nums.copyOfRange(i, r[index] + 1)) }
    }

    private fun arithmetic(nums: IntArray): Boolean {
        if (nums.size < 2) return false
        nums.sort()
        val diff = nums[1] - nums[0]
        for (i in 2 until nums.size) {
            if (nums[i] - nums[i - 1] != diff) return false
        }
        return true
    }
}
