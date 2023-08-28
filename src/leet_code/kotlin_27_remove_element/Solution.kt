package leet_code.kotlin_27_remove_element

class Solution {
    fun removeElement(nums: IntArray, `val`: Int): Int {
        var i = 0
        var j = 0
        while (j < nums.size) {
            if (nums[j] != `val`) {
                nums[i] = nums[j]
                i++
            }
            j++
        }
        return i
    }
}