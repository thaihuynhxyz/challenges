package leet_code.kotlin_228_summary_ranges

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertEquals(
            listOf("0->2", "4->5", "7"),
            Solution().summaryRanges(intArrayOf(0, 1, 2, 4, 5, 7)).sorted()
        )
        Assertions.assertEquals(
            listOf("0", "2->4", "6", "8->9"),
            Solution().summaryRanges(intArrayOf(0, 2, 3, 4, 6, 8, 9)).sorted()
        )
    }
}
