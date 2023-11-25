package leet_code.kotlin_1685_sum_of_absolute_differences_in_a_sorted_array

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertArrayEquals(
            intArrayOf(4, 3, 5),
            Solution().getSumAbsoluteDifferences(
                intArrayOf(2, 3, 5),
            )
        )
        Assertions.assertArrayEquals(
            intArrayOf(24, 15, 13, 15, 21),
            Solution().getSumAbsoluteDifferences(
                intArrayOf(1, 4, 6, 8, 10),
            )
        )
    }
}
