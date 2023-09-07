package leet_code.kotlin_141_linked_list_cycle

import leet_code.kotlin_data.ListNode
import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        val head = ListNode(3)
        head.next = ListNode(2)
        head.next!!.next = ListNode(0)
        head.next!!.next!!.next = ListNode(-4)
        head.next!!.next!!.next!!.next = head.next
        Assertions.assertEquals(true, instance.hasCycle(head))

        val head2 = ListNode(1)
        head2.next = ListNode(2)
        head2.next!!.next = head2
        Assertions.assertEquals(true, instance.hasCycle(head2))

        val head3 = ListNode(1)
        Assertions.assertEquals(false, instance.hasCycle(head3))
    }
}
