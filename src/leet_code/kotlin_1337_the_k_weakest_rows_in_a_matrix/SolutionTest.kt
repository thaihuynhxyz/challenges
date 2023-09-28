package leet_code.kotlin_1337_the_k_weakest_rows_in_a_matrix

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertArrayEquals(
            intArrayOf(2, 0, 3),
            Solution().kWeakestRows(
                arrayOf(
                    intArrayOf(1, 1, 0, 0, 0),
                    intArrayOf(1, 1, 1, 1, 0),
                    intArrayOf(1, 0, 0, 0, 0),
                    intArrayOf(1, 1, 0, 0, 0),
                    intArrayOf(1, 1, 1, 1, 1)
                ), 3
            )
        )

        Assertions.assertArrayEquals(
            intArrayOf(0, 2),
            Solution().kWeakestRows(
                arrayOf(
                    intArrayOf(1, 0, 0, 0),
                    intArrayOf(1, 1, 1, 1),
                    intArrayOf(1, 0, 0, 0),
                    intArrayOf(1, 0, 0, 0)
                ), 2
            )
        )
    }
}
