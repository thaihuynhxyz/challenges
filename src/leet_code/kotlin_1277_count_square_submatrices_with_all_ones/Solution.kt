package leet_code.kotlin_1277_count_square_submatrices_with_all_ones

class Solution {
    fun countSquares(matrix: Array<IntArray>): Int {
        val m = matrix.size
        val n = matrix[0].size
        var count = 0

        for (i in 0 until m) {
            for (j in 0 until n) {
                if (matrix[i][j] == 1) {
                    if (i > 0 && j > 0) {
                        matrix[i][j] += minOf(matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1])
                    }
                    count += matrix[i][j]
                }
            }
        }

        return count
    }
}