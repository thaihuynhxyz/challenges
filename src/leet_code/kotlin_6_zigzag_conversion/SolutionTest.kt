package leet_code.kotlin_6_zigzag_conversion

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals("PAHNAPLSIIGYIR", instance.convert("PAYPALISHIRING", 3))
        Assertions.assertEquals("PINALSIGYAHRPI", instance.convert("PAYPALISHIRING", 4))
        Assertions.assertEquals("A", instance.convert("A", 1))
    }
}
