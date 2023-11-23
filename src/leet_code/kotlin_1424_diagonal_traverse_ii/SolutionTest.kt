package leet_code.kotlin_1424_diagonal_traverse_ii

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertArrayEquals(
            intArrayOf(1, 4, 2, 7, 5, 3, 8, 6, 9),
            Solution().findDiagonalOrder(
                listOf(
                    listOf(1, 2, 3),
                    listOf(4, 5, 6),
                    listOf(7, 8, 9)
                )
            )
        )
    }
}
