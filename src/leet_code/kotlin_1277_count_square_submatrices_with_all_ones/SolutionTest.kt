package leet_code.kotlin_1277_count_square_submatrices_with_all_ones

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val matrix = arrayOf(
            intArrayOf(0, 1, 1, 1),
            intArrayOf(1, 1, 1, 1),
            intArrayOf(0, 1, 1, 1)
        )
        Assertions.assertEquals(15, Solution().countSquares(matrix))

        val matrix2 = arrayOf(
            intArrayOf(1, 0, 1),
            intArrayOf(1, 1, 0),
            intArrayOf(1, 1, 0)
        )
        Assertions.assertEquals(7, Solution().countSquares(matrix2))
    }
}
