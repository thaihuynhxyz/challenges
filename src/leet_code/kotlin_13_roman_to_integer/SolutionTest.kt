package leet_code.kotlin_13_roman_to_integer

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(3, instance.romanToInt("III"))
        Assertions.assertEquals(4, instance.romanToInt("IV"))
        Assertions.assertEquals(9, instance.romanToInt("IX"))
        Assertions.assertEquals(58, instance.romanToInt("LVIII"))
        Assertions.assertEquals(1994, instance.romanToInt("MCMXCIV"))
    }
}
