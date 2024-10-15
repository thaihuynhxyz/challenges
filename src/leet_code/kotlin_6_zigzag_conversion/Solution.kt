package leet_code.kotlin_6_zigzag_conversion

class Solution {
    fun convert(s: String, numRows: Int): String {
        if (numRows == 1) return s
        val result = StringBuilder()
        val step = 2 * numRows - 2
        for (i in 0 until numRows) {
            for (j in i until s.length step step) {
                result.append(s[j])
                if (i != 0 && i != numRows - 1) {
                    val temp = j + step - 2 * i
                    if (temp < s.length) result.append(s[temp])
                }
            }
        }
        return result.toString()
    }
}