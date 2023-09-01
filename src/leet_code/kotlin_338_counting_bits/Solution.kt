package leet_code.kotlin_338_counting_bits

class Solution {
    fun countBits(n: Int): IntArray {
        val res = IntArray(n + 1)
        for (i in 1 .. n) {
            res[i] = res[i / 2] + i % 2
        }
        return res
    }
}
