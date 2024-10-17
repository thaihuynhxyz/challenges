package leet_code.kotlin_670_maximum_swap

import kotlin.math.pow

class Solution {
    fun maximumSwap(num: Int): Int {
        val numArray = num.toString().toCharArray().map { it - '0' }
        if (numArray.size < 2) return num
        val max = numArray.foldIndexed(numArray[0] to 0) { index, acc, i ->
            when {
                i > acc.first || (i == acc.first && acc.second > 0) -> i to index
                acc.second == 0 -> i to 0
                else -> acc
            }
        }
        if (max.second == 0) return num
        var swapIndex: Pair<Int, Int>? = null
        return numArray.foldIndexed(0) { index, acc, i ->
            val pow = 10.0.pow(numArray.size - index - 1).toInt()
            if (swapIndex == null && i < max.first) {
                swapIndex = i to index
            }
            when (index) {
                swapIndex?.second -> acc + max.first * pow
                max.second -> acc + swapIndex!!.first * pow
                else -> acc + i * pow
            }
        }
    }
}