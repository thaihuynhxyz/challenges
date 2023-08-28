package leet_code.kotlin_2186_minimum_number_of_steps_to_make_two_strings_anagram_ii

import kotlin.math.abs

class MinimumNumberOfStepsToMakeTwoStringsAnagramII {
    fun minSteps(s: String, t: String): Int {
        val arr = IntArray(26)
        for (c in s) {
            arr[c - 'a']++
        }
        for (c in t) {
            arr[c - 'a']--
        }
        var ans = 0
        for (i in arr) {
            ans += abs(i)
        }
        return ans
    }
}
