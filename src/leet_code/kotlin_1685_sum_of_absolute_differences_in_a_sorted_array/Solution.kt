package leet_code.kotlin_1685_sum_of_absolute_differences_in_a_sorted_array

class Solution {
    fun getSumAbsoluteDifferences(nums: IntArray): IntArray {
        val result = IntArray(nums.size)
        val sum = nums.sum()
        var leftSum = 0
        var num: Int
        for (i in nums.indices) {
            num = nums[i]
            result[i] = (num * i) - leftSum + (sum - leftSum) - num * (nums.size - i)
            leftSum += num
        }
        return result
    }
}
