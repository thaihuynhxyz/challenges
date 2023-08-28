package leet_code.kotlin_80_remove_duplicates_from_sorted_array_ii

class Solution {
    fun removeDuplicates(nums: IntArray): Int {
        var i = 0
        var j = 1
        var count = 1
        while (j < nums.size) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j]
                count = 1
            } else if (count < 2) {
                nums[++i] = nums[j]
                count++
            }
            j++
        }
        return i + 1
    }
}