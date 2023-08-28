package leet_code.kotlin_169_majority_element

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(3, instance.majorityElement(intArrayOf(3, 2, 3)))
        Assertions.assertEquals(2, instance.majorityElement(intArrayOf(2, 2, 1, 1, 1, 2, 2)))
    }
}
