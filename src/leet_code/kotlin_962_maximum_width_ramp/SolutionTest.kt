package leet_code.kotlin_962_maximum_width_ramp

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(
            4,
            instance.maxWidthRamp(intArrayOf(6, 0, 8, 2, 1, 5))
        )
        Assertions.assertEquals(
            7,
            instance.maxWidthRamp(intArrayOf(9, 8, 1, 0, 1, 9, 4, 0, 4, 1))
        )
    }
}
