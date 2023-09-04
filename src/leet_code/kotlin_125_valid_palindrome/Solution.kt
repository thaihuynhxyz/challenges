package leet_code.kotlin_125_valid_palindrome

class Solution {
    fun isPalindrome(s: String): Boolean {
        var i = 0
        var j = s.lastIndex
        while (i < j) when {
            !s[i].isLetterOrDigit() -> i++
            !s[j].isLetterOrDigit() -> j--
            else -> if (s[i++].lowercaseChar() != s[j--].lowercaseChar()) return false
        }
        return true
    }
}