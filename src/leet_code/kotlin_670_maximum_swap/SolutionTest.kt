package leet_code.kotlin_670_maximum_swap

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun maxSlidingWindow() {
        val instance = Solution()
        Assertions.assertEquals(7236, instance.maximumSwap(2736))
        Assertions.assertEquals(9973, instance.maximumSwap(9973))
        Assertions.assertEquals(98863, instance.maximumSwap(98368))
        Assertions.assertEquals(511, instance.maximumSwap(115))
        Assertions.assertEquals(9913, instance.maximumSwap(1993))
        Assertions.assertEquals(90909011, instance.maximumSwap(10909091))
    }
}
