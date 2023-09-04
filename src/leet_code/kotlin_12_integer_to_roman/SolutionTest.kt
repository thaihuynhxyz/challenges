package leet_code.kotlin_12_integer_to_roman

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals("III", instance.intToRoman(3))
        Assertions.assertEquals("LVIII", instance.intToRoman(58))
        Assertions.assertEquals("MCMXCIV", instance.intToRoman(1994))
    }
}
