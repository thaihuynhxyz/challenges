package leet_code.kotlin_1337_the_k_weakest_rows_in_a_matrix

class Solution {
    fun kWeakestRows(mat: Array<IntArray>, k: Int): IntArray {
        return mat.mapIndexed { index, ints -> index to ints.lowerBound(0) }
            .sortedBy { it.second }
            .take(k)
            .map { it.first }
            .toIntArray()
    }
}

fun IntArray.lowerBound(value: Int): Int {
    var l = 0
    var r = lastIndex
    while (l <= r) {
        val mid = l + (r - l) / 2
        if (this[mid] > value) l = mid + 1
        else r = mid - 1
    }
    return l
}