package leet_code.coin_change_ii

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

class CoinChangeIITest {

    @Test
    fun change() {
        val instance = CoinChangeII()
        assertEquals(4, instance.change(5, intArrayOf(1, 2, 5)))
        assertEquals(0, instance.change(3, intArrayOf(2)))
        assertEquals(1, instance.change(10, intArrayOf(10)))
        assertEquals(35502874, instance.change(500, intArrayOf(3, 5, 7, 8, 9, 10, 11)))
    }
}