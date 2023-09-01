package leet_code.kotlin_2366_minimum_replacements_to_sort_the_array

import kotlin.math.ceil

class Solution {
    fun minimumReplacement(nums: IntArray): Long {
        var res = 0L
        var i = nums.lastIndex
        while (i > 0) {
            if (nums[i] < nums[i - 1]) {
                val div = ceil(nums[i - 1].toDouble() / nums[i]).toInt()
                nums[i - 1] = (nums[i - 1] / div)
                res += (div - 1)
            } else {
                i--
            }
        }
        return res
    }
}
