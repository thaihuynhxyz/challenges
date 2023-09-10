package leet_code.kotlin_2477_minimum_fuel_cost_to_report_to_the_capital

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertEquals(
            3,
            Solution().minimumFuelCost(
                arrayOf(
                    intArrayOf(0, 1),
                    intArrayOf(0, 2),
                    intArrayOf(0, 3),
                ),
                5,
            )
        )

        Assertions.assertEquals(
            7,
            Solution().minimumFuelCost(
                arrayOf(
                    intArrayOf(3, 1),
                    intArrayOf(3, 2),
                    intArrayOf(1, 0),
                    intArrayOf(0, 4),
                    intArrayOf(0, 5),
                    intArrayOf(4, 6),
                ),
                2,
            )
        )

        Assertions.assertEquals(
            0,
            Solution().minimumFuelCost(
                emptyArray(),
                1,
            )
        )

        // [[0,1],[0,2],[3,2],[0,4],[1,5],[5,6],[3,7]]
        Assertions.assertEquals(
            13,
            Solution().minimumFuelCost(
                arrayOf(
                    intArrayOf(0, 1),
                    intArrayOf(0, 2),
                    intArrayOf(3, 2),
                    intArrayOf(0, 4),
                    intArrayOf(1, 5),
                    intArrayOf(5, 6),
                    intArrayOf(3, 7),
                ),
                1,
            )
        )

        // [[0,1],[2,0]]
        Assertions.assertEquals(
            2,
            Solution().minimumFuelCost(
                arrayOf(
                    intArrayOf(0, 1),
                    intArrayOf(2, 0),
                ),
                1,
            )
        )

        // [[1,0],[0,2],[3,1],[1,4],[5,0]]
        Assertions.assertEquals(
            7,
            Solution().minimumFuelCost(
                arrayOf(
                    intArrayOf(1, 0),
                    intArrayOf(0, 2),
                    intArrayOf(3, 1),
                    intArrayOf(1, 4),
                    intArrayOf(5, 0),
                ),
                1,
            )
        )
    }
}
