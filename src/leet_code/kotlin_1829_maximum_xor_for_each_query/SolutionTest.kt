package leet_code.kotlin_1829_maximum_xor_for_each_query

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        val nums = intArrayOf(0, 1, 2, 2, 5, 7)
        val maximumBit = 3
        val expected = intArrayOf(4, 3, 6, 4, 6, 7)
        val result = instance.getMaximumXor(nums, maximumBit)

        Assertions.assertArrayEquals(expected, result)


        val nums2 = intArrayOf(2, 3, 4, 7)
        val maximumBit2 = 3
        val expected2 = intArrayOf(5, 2, 6, 5)
        val result2 = instance.getMaximumXor(nums2, maximumBit2)

        Assertions.assertArrayEquals(expected2, result2)

        val nums3 = intArrayOf(0, 1, 1, 3)
        val maximumBit3 = 2
        val expected3 = intArrayOf(0, 3, 2, 3)
        val result3 = instance.getMaximumXor(nums3, maximumBit3)

        Assertions.assertArrayEquals(expected3, result3)
    }
}
