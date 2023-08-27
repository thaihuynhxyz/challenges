package leet_code.kotlin_459_repeated_substring_pattern

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class RepeatedSubstringPatternTest {
    @Test
    fun maxSlidingWindow() {
        val instance = RepeatedSubstringPattern()
        Assertions.assertTrue(instance.repeatedSubstringPattern("abab"))
        Assertions.assertTrue(instance.repeatedSubstringPattern2("abab"))
        Assertions.assertFalse(instance.repeatedSubstringPattern("aba"))
        Assertions.assertFalse(instance.repeatedSubstringPattern2("aba"))
        Assertions.assertTrue(instance.repeatedSubstringPattern("abcabcabcabc"))
        Assertions.assertTrue(instance.repeatedSubstringPattern2("abcabcabcabc"))
        Assertions.assertTrue(instance.repeatedSubstringPattern("abcababcababcab"))
        Assertions.assertTrue(instance.repeatedSubstringPattern2("abcababcababcab"))
        Assertions.assertTrue(instance.repeatedSubstringPattern("abaababaab"))
        Assertions.assertTrue(instance.repeatedSubstringPattern2("abaababaab"))
    }
}
