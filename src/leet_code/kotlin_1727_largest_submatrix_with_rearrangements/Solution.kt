package leet_code.kotlin_1727_largest_submatrix_with_rearrangements

class Solution {
    fun largestSubmatrix(matrix: Array<IntArray>): Int {
        for (i in matrix.indices) {
            for (j in matrix[0].indices) {
                if (i > 0 && matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j]
                }
            }
        }
        return matrix.maxOf {
            it.sortedDescending().mapIndexed { index, i -> i * (index + 1) }.max()
        }
    }
}
