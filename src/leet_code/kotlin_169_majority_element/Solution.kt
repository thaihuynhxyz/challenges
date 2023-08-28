package leet_code.kotlin_169_majority_element

class Solution {
    fun majorityElement(nums: IntArray): Int {
        var count = 0
        var candidate = 0
        for (num in nums) {
            if (count == 0) {
                candidate = num
            }
            count += if (num == candidate) 1 else -1
        }
        return candidate
    }
}