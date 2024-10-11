package leet_code.kotlin_962_maximum_width_ramp

typealias DecreaseStack = MutableList<Pair<Int, Int>>

fun DecreaseStack.popWhileLestThanOrEqual(num: Int): Int? {
    var minIndex: Int? = null
    val iterator = listIterator(size)
    while (iterator.hasPrevious()) {
        val i = iterator.previous()
        if (i.second > num) break
        minIndex = i.first
        iterator.remove()
    }
    return minIndex
}

fun IntArray.toDecreaseStack(): DecreaseStack {
    return foldIndexed(mutableListOf()) { index, acc, i ->
        acc.apply {
            if (isEmpty() || last().second > i) add(index to i)
        }
    }
}

fun Int?.widthRampTo(index: Int): Int = this?.let { index - it } ?: 0

class Solution {
    fun maxWidthRamp(nums: IntArray): Int {
        val decreaseStack = nums.toDecreaseStack()
        return nums.foldRightIndexed(0) { index, i, acc ->
            acc.coerceAtLeast(decreaseStack.popWhileLestThanOrEqual(i).widthRampTo(index)).also {
                if (decreaseStack.isEmpty()) return it
            }
        }
    }
}
