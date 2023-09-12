package leet_code.kotlin_21_merge_two_sorted_lists

import leet_code.kotlin_data.ListNode

class Solution {
    fun mergeTwoLists(list1: ListNode<Int>?, list2: ListNode<Int>?): ListNode<Int>? {
        var l1 = list1
        var l2 = list2
        val dummy = ListNode(0)
        var cur = dummy
        while (l1 != null && l2 != null) {
            if (l1.`val` < l2.`val`) {
                cur.next = l1
                l1 = l1.next
            } else {
                cur.next = l2
                l2 = l2.next
            }
            cur = cur.next!!
        }
        cur.next = l1 ?: l2
        return dummy.next
    }
}
