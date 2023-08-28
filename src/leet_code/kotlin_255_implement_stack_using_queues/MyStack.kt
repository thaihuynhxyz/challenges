package leet_code.kotlin_255_implement_stack_using_queues

import java.util.*

class MyStack {
    private val queue = LinkedList<Int>()

    fun push(x: Int) {
        queue.offer(x)
    }

    fun pop(): Int {
        for (i in 1 until queue.size) {
            queue.offer(queue.poll())
        }
        return queue.poll()
    }

    fun top(): Int {
        return pop().also { push(it) }
    }

    fun empty(): Boolean {
        return queue.isEmpty()
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */
