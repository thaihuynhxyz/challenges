package leet_code.kotlin_228_summary_ranges

class Solution {
    fun summaryRanges(nums: IntArray): List<String> {
        val ans = mutableListOf<String>()
        var i = 0
        while (i < nums.size) {
            var j = i
            while (j + 1 < nums.size && nums[j + 1] == nums[j] + 1) {
                j++
            }
            if (i == j) {
                ans.add(nums[i].toString())
            } else {
                ans.add("${nums[i]}->${nums[j]}")
            }
            i = j + 1
        }
        return ans
    }
}
