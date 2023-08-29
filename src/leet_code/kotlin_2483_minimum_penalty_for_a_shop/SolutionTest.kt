package leet_code.kotlin_2483_minimum_penalty_for_a_shop

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(2, instance.bestClosingTime("YYNY"))
        Assertions.assertEquals(0, instance.bestClosingTime("NNNNN"))
        Assertions.assertEquals(4, instance.bestClosingTime("YYYY"))
    }
}
