package leet_code.kotlin_1942_the_number_of_the_smallest_unoccupied_chair

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(
            1,
            instance.smallestChair(
                arrayOf(
                    intArrayOf(1, 4),
                    intArrayOf(2, 3),
                    intArrayOf(4, 6),
                ),
                1,
            )
        )
        Assertions.assertEquals(
            2,
            instance.smallestChair(
                arrayOf(
                    intArrayOf(3, 10),
                    intArrayOf(1, 5),
                    intArrayOf(2, 6),
                ),
                0,
            )
        )
        Assertions.assertEquals(
            2,
            instance.smallestChair(
                arrayOf(
                    intArrayOf(33889, 98676),
                    intArrayOf(80071, 89737),
                    intArrayOf(44118, 52565),
                    intArrayOf(52992, 84310),
                    intArrayOf(78492, 88209),
                    intArrayOf(21695, 67063),
                    intArrayOf(84622, 95452),
                    intArrayOf(98048, 98856),
                    intArrayOf(98411, 99433),
                    intArrayOf(55333, 56548),
                    intArrayOf(65375, 88566),
                    intArrayOf(55011, 62821),
                    intArrayOf(48548, 48656),
                    intArrayOf(87396, 94825),
                    intArrayOf(55273, 81868),
                    intArrayOf(75629, 91467),
                ),
                6,
            )
        )
    }
}
