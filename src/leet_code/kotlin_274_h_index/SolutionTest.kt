package leet_code.kotlin_274_h_index

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(3, instance.hIndex(intArrayOf(3, 0, 6, 1, 5)))
        Assertions.assertEquals(1, instance.hIndex(intArrayOf(1, 3, 1)))
    }
}
