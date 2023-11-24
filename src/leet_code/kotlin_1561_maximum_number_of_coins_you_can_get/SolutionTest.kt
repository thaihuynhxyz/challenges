package leet_code.kotlin_1561_maximum_number_of_coins_you_can_get

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertEquals(
            9,
            Solution().maxCoins(
                intArrayOf(2, 4, 1, 2, 7, 8)
            )
        )
    }
}
