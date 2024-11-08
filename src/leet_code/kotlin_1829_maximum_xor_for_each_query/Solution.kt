package leet_code.kotlin_1829_maximum_xor_for_each_query

class Solution {
    fun getMaximumXor(nums: IntArray, maximumBit: Int): IntArray {
        val n = nums.size
        val res = IntArray(n)
        val max = (1 shl maximumBit) - 1
        var xor = 0
        nums.forEachIndexed { index, i ->
            xor = xor xor i
            res[n - index - 1] = xor xor max
        }
        return res
    }
}