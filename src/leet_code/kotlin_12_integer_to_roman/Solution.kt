package leet_code.kotlin_12_integer_to_roman

class Solution {
    fun intToRoman(num: Int): String {
        var n = num
        var result = ""

        val most = fun(n: Int, block: (i: Int, roman: String) -> Unit) = when {
            n >= 1000 -> block(1000, "M")
            n >= 900 -> block(900, "CM")
            n >= 500 -> block(500, "D")
            n >= 400 -> block(400, "CD")
            n >= 100 -> block(100, "C")
            n >= 90 -> block(90, "XC")
            n >= 50 -> block(50, "L")
            n >= 40 -> block(40, "XL")
            n >= 10 -> block(10, "X")
            n >= 9 -> block(9, "IX")
            n >= 5 -> block(5, "V")
            n >= 4 -> block(4, "IV")
            else -> block(1, "I")
        }

        while (n != 0) most(n) { i, roman ->
            n -= i
            result += roman
        }
        return result
    }
}