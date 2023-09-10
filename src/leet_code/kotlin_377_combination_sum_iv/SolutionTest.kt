package leet_code.kotlin_377_combination_sum_iv

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertEquals(7, Solution().combinationSum4(intArrayOf(1, 2, 3), 4))
        Assertions.assertEquals(0, Solution().combinationSum4(intArrayOf(9), 3))
    }
}
