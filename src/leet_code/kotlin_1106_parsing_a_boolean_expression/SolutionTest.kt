package leet_code.kotlin_1106_parsing_a_boolean_expression

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(
            false,
            instance.parseBoolExpr("&(|(f))")
        )
        Assertions.assertEquals(
            true,
            instance.parseBoolExpr("|(f,f,f,t)")
        )
        Assertions.assertEquals(
            true,
            instance.parseBoolExpr("!(&(f,t))")
        )
    }
}
