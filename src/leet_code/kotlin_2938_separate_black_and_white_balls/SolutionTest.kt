package leet_code.kotlin_2938_separate_black_and_white_balls

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(1, instance.minimumSteps("101"))
        Assertions.assertEquals(2, instance.minimumSteps("100"))
        Assertions.assertEquals(0, instance.minimumSteps("0111"))
        Assertions.assertEquals(65, instance.minimumSteps("111111111100100010"))
    }
}
