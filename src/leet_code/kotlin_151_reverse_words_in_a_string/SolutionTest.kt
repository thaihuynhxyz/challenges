package leet_code.kotlin_151_reverse_words_in_a_string

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val solution = Solution()
        Assertions.assertEquals("blue is sky the", solution.reverseWords("the sky is blue"))
        Assertions.assertEquals("world! hello", solution.reverseWords("  hello world!  "))
        Assertions.assertEquals("example good a", solution.reverseWords("a good   example"))
        Assertions.assertEquals("f df asdasd", solution.reverseWords(" asdasd df f"))
    }
}
