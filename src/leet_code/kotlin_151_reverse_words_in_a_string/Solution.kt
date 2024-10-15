package leet_code.kotlin_151_reverse_words_in_a_string

class Solution {
    fun reverseWords(s: String): String {
        val words = StringBuilder()
        var endIndex = -1
        for (index in s.lastIndex downTo 0) {
            if (s[index] != ' ' && endIndex == -1) {
                endIndex = index
                if (words.isNotEmpty()) words.append(' ')
            }
            when {
                s[index] == ' ' -> index + 1..endIndex
                index == 0 -> 0..endIndex
                else -> null
            }?.takeIf { endIndex != -1 }?.let {
                for (i in it) words.append(s[i])
                endIndex = -1
            }
        }
        return words.toString()
    }
}