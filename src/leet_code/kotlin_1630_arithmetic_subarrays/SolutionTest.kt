package leet_code.kotlin_1630_arithmetic_subarrays

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertEquals(
            listOf(true, false, true),
            Solution().checkArithmeticSubarrays(
                intArrayOf(4, 6, 5, 9, 3, 7),
                intArrayOf(0, 0, 2),
                intArrayOf(2, 3, 5)
            )
        )
        Assertions.assertEquals(
            listOf(false, true, false, false, true, true),
            Solution().checkArithmeticSubarrays(
                intArrayOf(-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10),
                intArrayOf(0, 1, 6, 4, 8, 7),
                intArrayOf(4, 4, 9, 7, 9, 10)
            )
        )
    }
}
