package leet_code.kotlin_30_substring_with_concatenation_of_all_words

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertEquals(
            listOf(0, 9),
            Solution().findSubstring("barfoothefoobarman", arrayOf("foo", "bar"))
        )
        Assertions.assertEquals(
            emptyList<Int>(),
            Solution().findSubstring("wordgoodgoodgoodbestword", arrayOf("word", "good", "best", "word"))
        )
        Assertions.assertEquals(
            listOf(6, 9, 12),
            Solution().findSubstring("barfoofoobarthefoobarman", arrayOf("bar", "foo", "the"))
        )
    }
}
