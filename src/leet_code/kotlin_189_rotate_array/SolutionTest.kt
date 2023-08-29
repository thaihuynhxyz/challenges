package leet_code.kotlin_189_rotate_array

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        val nums = intArrayOf(1, 2, 3, 4, 5, 6, 7)
        instance.rotate(nums, 3)
        Assertions.assertArrayEquals(intArrayOf(5, 6, 7, 1, 2, 3, 4), nums)

        val nums2 = intArrayOf(-1, -100, 3, 99)
        instance.rotate(nums2, 2)
        Assertions.assertArrayEquals(intArrayOf(3, 99, -1, -100), nums2)

        val nums3 = intArrayOf(1, 2)
        instance.rotate(nums3, 3)
        Assertions.assertArrayEquals(intArrayOf(2, 1), nums3)

        val nums4 = intArrayOf(1, 2)
        instance.rotate(nums4, 2)
        Assertions.assertArrayEquals(intArrayOf(1, 2), nums4)

        val nums5 = intArrayOf(1, 2, 3, 4, 5, 6)
        instance.rotate(nums5, 4)
        Assertions.assertArrayEquals(intArrayOf(3, 4, 5, 6, 1, 2), nums5)

        val nums6 = intArrayOf(
            1,
            2,
            3,
            4,
            5,
            6,
            7,
            8,
            9,
            10,
            11,
            12,
            13,
            14,
            15,
            16,
            17,
            18,
            19,
            20,
            21,
            22,
            23,
            24,
            25,
            26,
            27
        )
        instance.rotate(nums6, 38)
        Assertions.assertArrayEquals(
            intArrayOf(
                17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
            ), nums6
        )
    }
}
