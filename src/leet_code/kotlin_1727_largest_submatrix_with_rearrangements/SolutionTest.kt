package leet_code.kotlin_1727_largest_submatrix_with_rearrangements

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertEquals(
            4,
            Solution().largestSubmatrix(
                arrayOf(
                    intArrayOf(0, 0, 1),
                    intArrayOf(1, 1, 1),
                    intArrayOf(1, 0, 1)
                )
            )
        )
        Assertions.assertEquals(
            3,
            Solution().largestSubmatrix(
                arrayOf(
                    intArrayOf(1, 0, 1, 0, 1)
                )
            )
        )
        Assertions.assertEquals(
            2,
            Solution().largestSubmatrix(
                arrayOf(
                    intArrayOf(1, 1, 0),
                    intArrayOf(1, 0, 1)
                )
            )
        )
    }
}
