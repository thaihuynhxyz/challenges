package leet_code.kotlin_26_remove_duplicates_from_sorted_array

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(2, instance.removeDuplicates(intArrayOf(1, 1, 2)))
        Assertions.assertEquals(5, instance.removeDuplicates(intArrayOf(0, 0, 1, 1, 1, 2, 2, 3, 3, 4)))
    }
}
