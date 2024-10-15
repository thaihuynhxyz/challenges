package leet_code.kotlin_2938_separate_black_and_white_balls

class Solution {
    fun minimumSteps(s: String): Long {
        var res = 0L
        var start = 0
        var end = s.lastIndex
        while (start < end) {
            while (start < end && s[start] == '0') start++
            while (end > start && s[end] == '1') end--
            if (start < end) {
                res += end-- - start++
            } else {
                break
            }
        }
        return res
    }
}
