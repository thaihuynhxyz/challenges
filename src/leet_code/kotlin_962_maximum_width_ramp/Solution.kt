package leet_code.kotlin_962_maximum_width_ramp

import kotlin.math.*

typealias DecreaseStack = MutableList<Pair<Int, Int>>

fun DecreaseStack.canPush(num: Int): Boolean = isEmpty() || num < last().second

fun DecreaseStack.popWhileLestThanOrEqual(num: Int, index: Int): Int {
    var accumulator = 0
    val iterator = listIterator(size)
    while (iterator.hasPrevious()) {
        val i = iterator.previous()
        if (i.second > num) break
        accumulator = max(accumulator, index - i.first)
        iterator.remove()
    }
    return accumulator
}

fun IntArray.toDecreaseStack(): DecreaseStack {
    return foldIndexed(mutableListOf()) { index, acc, i ->
        acc.also { if (acc.canPush(i)) acc.add(index to i) }
    }
}

class Solution {
    fun maxWidthRamp(nums: IntArray): Int {
        val decreaseStack = nums.toDecreaseStack()
        return nums.foldRightIndexed(0) { index, i, acc ->
            max(decreaseStack.popWhileLestThanOrEqual(i, index), acc).also {
                if (decreaseStack.isEmpty()) return it
            }
        }
    }
}
