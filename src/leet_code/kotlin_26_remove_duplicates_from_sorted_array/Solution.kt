package leet_code.kotlin_26_remove_duplicates_from_sorted_array

class Solution {
    fun removeDuplicates(nums: IntArray): Int {
        var i = 0
        var j = 0
        while (j < nums.size) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j]
            }
            j++
        }
        return i + 1
    }
}