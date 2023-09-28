package leet_code.kotlin_905_sort_array_by_parity

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertArrayEquals(
            intArrayOf(4, 2, 1, 3),
            Solution().sortArrayByParity(intArrayOf(3, 1, 2, 4))
        )

        Assertions.assertArrayEquals(
            intArrayOf(0),
            Solution().sortArrayByParity(intArrayOf(0))
        )
    }
}
