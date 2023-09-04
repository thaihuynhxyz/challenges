package leet_code.kotlin_380_insert_delete_getrandom_o1

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class RandomizedSetTest {
    @Test
    fun test() {
        val instance = RandomizedSet()
        Assertions.assertEquals(true, instance.insert(1))
        Assertions.assertEquals(false, instance.remove(2))
        Assertions.assertEquals(true, instance.insert(2))
        Assertions.assertEquals(true, instance.getRandom() in 1..2)
        Assertions.assertEquals(true, instance.remove(1))
        Assertions.assertEquals(false, instance.insert(2))
        Assertions.assertEquals(2, instance.getRandom())
    }
}
