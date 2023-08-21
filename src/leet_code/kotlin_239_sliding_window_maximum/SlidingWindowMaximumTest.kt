package leet_code.kotlin_239_sliding_window_maximum

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SlidingWindowMaximumTest {
    @Test
    fun maxSlidingWindow() {
        val instance = SlidingWindowMaximum()
        Assertions.assertArrayEquals(
            intArrayOf(3, 3, 5, 5, 6, 7),
            instance.maxSlidingWindow(intArrayOf(1, 3, -1, -3, 5, 3, 6, 7), 3)
        )
        Assertions.assertArrayEquals(
            intArrayOf(1),
            instance.maxSlidingWindow(intArrayOf(1), 1)
        )
    }
}
