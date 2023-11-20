package leet_code.kotlin_2391_minimum_amount_of_time_to_collect_garbage

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertEquals(
            21,
            Solution().garbageCollection(
                arrayOf(
                    "G", "P", "GP", "GG"
                ),
                intArrayOf(2, 4, 3)
            )
        )
        Assertions.assertEquals(
            37,
            Solution().garbageCollection(
                arrayOf(
                    "MMM", "PGM", "GP"
                ),
                intArrayOf(3, 10)
            )
        )
    }
}
