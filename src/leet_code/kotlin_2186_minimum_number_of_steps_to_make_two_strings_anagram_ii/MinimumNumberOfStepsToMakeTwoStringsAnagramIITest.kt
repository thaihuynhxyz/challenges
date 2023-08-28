package leet_code.kotlin_2186_minimum_number_of_steps_to_make_two_strings_anagram_ii

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class MinimumNumberOfStepsToMakeTwoStringsAnagramIITest {
    @Test
    fun maxSlidingWindow() {
        val instance = MinimumNumberOfStepsToMakeTwoStringsAnagramII()
        Assertions.assertEquals(7, instance.minSteps("leetcode", "coats"))
        Assertions.assertEquals(0, instance.minSteps("night", "thing"))
    }
}
