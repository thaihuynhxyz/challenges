package leet_code.kotlin_80_remove_duplicates_from_sorted_array_ii

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(5, instance.removeDuplicates(intArrayOf(1, 1, 1, 2, 2, 3)))
        Assertions.assertEquals(7, instance.removeDuplicates(intArrayOf(0, 0, 1, 1, 1, 1, 2, 3, 3)))
    }
}
