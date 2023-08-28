package leet_code.kotlin_255_implement_stack_using_queues

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class MyStackTest {
    @Test
    fun test() {
        val instance = MyStack()
        instance.push(1)
        instance.push(2)
        Assertions.assertEquals(2, instance.top())
        Assertions.assertEquals(2, instance.pop())
        Assertions.assertFalse(instance.empty())
    }
}
