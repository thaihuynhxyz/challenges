package leet_code.kotlin_905_sort_array_by_parity

class Solution {
    fun sortArrayByParity(nums: IntArray): IntArray {
        var l = 0
        var r = nums.lastIndex
        while (l < r) {
            if (nums[l] % 2 == 0) l++
            else {
                nums[l] = nums[r].also { nums[r] = nums[l] }
                r--
            }
        }
        return nums
    }
}