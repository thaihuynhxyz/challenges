package leet_code.kotlin_48_rotate_image

class Solution {
    fun rotate(matrix: Array<IntArray>) {
        val n = matrix.size
        for (i in 0 until n / 2) {
            for (j in i until n - i - 1) {
                val temp = matrix[i][j]
                matrix[i][j] = matrix[n - j - 1][i]
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]
                matrix[j][n - i - 1] = temp
            }
        }
    }
}