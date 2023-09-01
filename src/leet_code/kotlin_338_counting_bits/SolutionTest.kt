package leet_code.kotlin_338_counting_bits

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertArrayEquals(intArrayOf(0, 1, 1), instance.countBits(2))
        Assertions.assertArrayEquals(intArrayOf(0, 1, 1, 2, 1, 2), instance.countBits(5))
    }
}
