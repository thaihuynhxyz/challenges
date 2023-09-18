package leet_code.kotlin_86_partition_list

import leet_code.kotlin_data.ListNode

/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class PartitionList {
    fun partition(head: ListNode<Int>?, x: Int): ListNode<Int>? {
        var head1: ListNode<Int>? = null
        var head2: ListNode<Int>? = null
        var tail1: ListNode<Int>? = null
        var tail2: ListNode<Int>? = null
        var node = head
        while (node != null) {
            if (node.`val` < x) {
                if (head1 == null) {
                    head1 = node
                    tail1 = node
                } else {
                    tail1!!.next = node
                    tail1 = tail1.next
                }
            } else {
                if (head2 == null) {
                    head2 = node
                    tail2 = node
                } else {
                    tail2!!.next = node
                    tail2 = tail2.next
                }
            }
            node = node.next
        }
        tail1?.next = head2
        tail2?.next = null
        return head1 ?: head2
    }
}
