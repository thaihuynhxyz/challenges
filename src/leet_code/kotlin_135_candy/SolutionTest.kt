package leet_code.kotlin_135_candy

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(5, instance.candy(intArrayOf(1, 0, 2)))
        Assertions.assertEquals(4, instance.candy(intArrayOf(1, 2, 2)))
    }
}
