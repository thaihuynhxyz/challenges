package leet_code.kotlin_92_reverse_linked_list_ii

import leet_code.kotlin_data.ListNode

/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 */

class Solution {
    fun reverseBetween(head: ListNode?, left: Int, right: Int): ListNode? {
        val dummy = ListNode(0)
        dummy.next = head
        var pre: ListNode? = dummy
        repeat(left - 1) { pre = pre!!.next }

        val start = pre!!.next
        var then = start!!.next
        repeat(right - left) {
            start.next = then!!.next
            then!!.next = pre!!.next
            pre!!.next = then
            then = start.next
        }
        return dummy.next
    }
}