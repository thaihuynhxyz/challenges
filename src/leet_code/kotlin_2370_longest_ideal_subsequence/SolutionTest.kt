package leet_code.kotlin_2370_longest_ideal_subsequence

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(4, instance.longestIdealString("acfgbd", 2))
        Assertions.assertEquals(4, instance.longestIdealString("abcd", 3))
        Assertions.assertEquals(2, instance.longestIdealString("pvjcci", 4))
    }
}
