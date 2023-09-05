package leet_code.kotlin_383_ransom_note

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertFalse(instance.canConstruct("a", "b"))
        Assertions.assertFalse(instance.canConstruct("aa", "ab"))
        Assertions.assertTrue(instance.canConstruct("aa", "aab"))
    }
}
