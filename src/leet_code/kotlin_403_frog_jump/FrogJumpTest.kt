package leet_code.kotlin_403_frog_jump

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class FrogJumpTest {
    @Test
    fun canCross() {
        val instance = FrogJump()
        Assertions.assertTrue(instance.canCross(intArrayOf(0, 1, 3, 5, 6, 8, 12, 17)))
        Assertions.assertFalse(instance.canCross(intArrayOf(0, 1, 2, 3, 4, 8, 9, 11)))
    }
}
