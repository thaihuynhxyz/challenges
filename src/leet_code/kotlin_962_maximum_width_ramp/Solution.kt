package leet_code.kotlin_962_maximum_width_ramp

typealias IndexNum = Pair<Int, Int>
typealias DecreaseStack = MutableList<IndexNum>

private operator fun IndexNum.compareTo(indexNum: IndexNum): Int {
    return second.compareTo(indexNum.second)
}

private fun IndexNum.widthTo(indexNum: IndexNum): Int {
    return first - indexNum.first
}

private fun IntArray.toDecreaseStack(): DecreaseStack {
    return foldIndexed(mutableListOf()) { index, acc, i ->
        acc.pushIfDecrease(indexNum = index to i)
    }
}

private fun DecreaseStack.pushIfDecrease(indexNum: IndexNum): DecreaseStack {
    if (isEmpty() || last() > indexNum) add(indexNum)
    return this
}

private fun DecreaseStack.popWhileFindMaxWidthRamp(indexNum: IndexNum): Int {
    var maxWidth = 0
    val iterator = listIterator(size)
    while (iterator.hasPrevious()) {
        val i = iterator.previous()
        if (i > indexNum) break
        maxWidth = maxWidth.coerceAtLeast(indexNum.widthTo(i))
        iterator.remove()
    }
    return maxWidth
}

/**
 * 1. Build a decrease stack from the input array.
 * 2. Iterate the input array from right to left.
 *  2.1. Pop the decrease stack while finding the maximum width ramp.
 *   2.1.1. Calculate the width to the current index.
 *   2.1.2. Update the maximum width ramp.
 *   2.1.3. Remove the last element from the decrease stack.
 *   2.1.4. Continue until the decrease stack is empty or the last element is greater than the current index.
 *  2.2. Update the maximum width ramp.
 *  2.3. If the decrease stack is empty, return the maximum width ramp.
 */
class Solution {
    fun maxWidthRamp(nums: IntArray): Int {
        val decreaseStack = nums.toDecreaseStack()
        return nums.foldRightIndexed(0) { index, i, acc ->
            acc.coerceAtLeast(decreaseStack.popWhileFindMaxWidthRamp(index to i)).also {
                if (decreaseStack.isEmpty()) return it
            }
        }
    }
}
