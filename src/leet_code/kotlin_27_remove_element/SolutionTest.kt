package leet_code.kotlin_27_remove_element

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(2, instance.removeElement(intArrayOf(3, 2, 2, 3), 3))
        Assertions.assertEquals(5, instance.removeElement(intArrayOf(0, 1, 2, 2, 3, 0, 4, 2), 2))
    }
}
