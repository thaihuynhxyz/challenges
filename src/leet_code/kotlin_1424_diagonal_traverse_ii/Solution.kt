package leet_code.kotlin_1424_diagonal_traverse_ii

class Solution {
    fun findDiagonalOrder(nums: List<List<Int>>): IntArray {
        val map = mutableMapOf<Int, MutableList<Int>>()
        var maxKey = 0
        for (i in nums.indices.reversed()) {
            for (j in nums[i].indices) {
                map.getOrPut(i + j) { mutableListOf() }.add(nums[i][j])
                maxKey = maxOf(maxKey, i + j)
            }
        }
        val ans = mutableListOf<Int>()
        for (i in 0..maxKey) {
            ans.addAll(map[i]!!)
        }
        return ans.toIntArray()
    }
}
