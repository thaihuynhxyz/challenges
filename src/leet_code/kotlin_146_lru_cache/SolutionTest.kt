package leet_code.kotlin_146_lru_cache

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val cache = LRUCache(2)
        cache[1] = 1
        cache[2] = 2
        Assertions.assertEquals(1, cache[1])
        cache[3] = 3
        Assertions.assertEquals(-1, cache[2])
        cache[4] = 4
        Assertions.assertEquals(-1, cache[1])
        Assertions.assertEquals(3, cache[3])
        Assertions.assertEquals(4, cache[4])
    }
}
