package leet_code.kotlin_2406_divide_intervals_into_minimum_number_of_groups

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertEquals(
            3,
            Solution().minGroups(
                arrayOf(
                    intArrayOf(5, 10),
                    intArrayOf(6, 8),
                    intArrayOf(1, 5),
                    intArrayOf(2, 3),
                    intArrayOf(1, 10),
                )
            )
        )
        Assertions.assertEquals(
            1,
            Solution().minGroups(
                arrayOf(
                    intArrayOf(1, 3),
                    intArrayOf(5, 6),
                    intArrayOf(8, 10),
                    intArrayOf(11, 13),
                )
            )
        )
        Assertions.assertEquals(
            1,
            Solution().minGroups(
                arrayOf(
                    intArrayOf(1, 1),
                )
            )
        )
        Assertions.assertEquals(
            3,
            Solution().minGroups1(
                arrayOf(
                    intArrayOf(5, 10),
                    intArrayOf(6, 8),
                    intArrayOf(1, 5),
                    intArrayOf(2, 3),
                    intArrayOf(1, 10),
                )
            )
        )
        Assertions.assertEquals(
            1,
            Solution().minGroups1(
                arrayOf(
                    intArrayOf(1, 3),
                    intArrayOf(5, 6),
                    intArrayOf(8, 10),
                    intArrayOf(11, 13),
                )
            )
        )
        Assertions.assertEquals(
            1,
            Solution().minGroups1(
                arrayOf(
                    intArrayOf(1, 1),
                )
            )
        )
        Assertions.assertEquals(
            3,
            Solution().minGroups2(
                arrayOf(
                    intArrayOf(5, 10),
                    intArrayOf(6, 8),
                    intArrayOf(1, 5),
                    intArrayOf(2, 3),
                    intArrayOf(1, 10),
                )
            )
        )
        Assertions.assertEquals(
            1,
            Solution().minGroups2(
                arrayOf(
                    intArrayOf(1, 3),
                    intArrayOf(5, 6),
                    intArrayOf(8, 10),
                    intArrayOf(11, 13),
                )
            )
        )
        Assertions.assertEquals(
            1,
            Solution().minGroups2(
                arrayOf(
                    intArrayOf(1, 1),
                )
            )
        )
    }
}
