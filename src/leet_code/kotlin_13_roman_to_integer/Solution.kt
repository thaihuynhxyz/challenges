package leet_code.kotlin_13_roman_to_integer

class Solution {
    fun romanToInt(s: String): Int {
        var result = 0
        var prev = 0
        for (c in s.reversed()) {
            val curr = when (c) {
                'I' -> 1
                'V' -> 5
                'X' -> 10
                'L' -> 50
                'C' -> 100
                'D' -> 500
                else -> 1000
            }
            if (curr < prev) {
                result -= curr
            } else {
                result += curr
            }
            prev = curr
        }
        return result
    }
}