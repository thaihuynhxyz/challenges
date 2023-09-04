package leet_code.kotlin_125_valid_palindrome

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(true, instance.isPalindrome("A man, a plan, a canal: Panama"))
        Assertions.assertEquals(false, instance.isPalindrome("race a car"))
        Assertions.assertEquals(true, instance.isPalindrome(" "))
    }
}
