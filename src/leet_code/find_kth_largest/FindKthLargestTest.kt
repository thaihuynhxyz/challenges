package leet_code.find_kth_largest

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

class FindKthLargestTest {
    @Test
    fun findKthLargest() {
        val instance = FindKthLargest()
        assertEquals(5, instance.findKthLargest(intArrayOf(3, 2, 1, 5, 6, 4), 2))
        assertEquals(4, instance.findKthLargest(intArrayOf(3, 2, 3, 1, 2, 4, 5, 5, 6), 4))
    }
}
