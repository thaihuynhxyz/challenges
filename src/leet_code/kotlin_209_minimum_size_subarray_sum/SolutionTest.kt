package leet_code.kotlin_209_minimum_size_subarray_sum

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(2, instance.minSubArrayLen(7, intArrayOf(2, 3, 3, 2, 4, 4)))
        Assertions.assertEquals(1, instance.minSubArrayLen(4, intArrayOf(1, 4, 4)))
        Assertions.assertEquals(0, instance.minSubArrayLen(11, intArrayOf(1, 1, 1, 1, 1, 1, 1, 1)))
    }
}
