package leet_code.kotlin_30_substring_with_concatenation_of_all_words

class Solution {
    fun findSubstring(s: String, words: Array<String>): List<Int> {
        val ans = mutableListOf<Int>()
        if (words.isEmpty()) return ans
        val wordLen = words[0].length
        val wordCount = words.size
        val totalLen = wordLen * wordCount
        val map = mutableMapOf<String, Int>()
        for (word in words) {
            map[word] = map.getOrDefault(word, 0) + 1
        }
        val tempMap = mutableMapOf<String, Int>()
        for (i in 0..s.length - totalLen) {
            tempMap.clear()
            for (j in i until i + totalLen step wordLen) {
                val word = s.substring(j, j + wordLen)
                if (!map.containsKey(word)) break
                tempMap[word] = tempMap.getOrDefault(word, 0) + 1
                if (tempMap[word]!! > map[word]!!) break
                if (j == i + totalLen - wordLen) ans.add(i)
            }
        }
        return ans
    }
}