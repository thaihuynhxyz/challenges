package leet_code.kotlin_1814_count_nice_pairs_in_an_array

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance =
        Assertions.assertEquals(
            2,
            Solution().countNicePairs(
                intArrayOf(42, 11, 1, 97)
            )
        )
        Assertions.assertEquals(
            4,
            Solution().countNicePairs(
                intArrayOf(13, 10, 35, 24, 76)
            )
        )
    }
}
