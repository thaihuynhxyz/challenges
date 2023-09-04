package leet_code.kotlin_141_linked_list_cycle

/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 */
class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

class Solution {
    fun hasCycle(head: ListNode?): Boolean {
        var slow = head
        var fast = head?.next
        while (fast != null && fast != slow) {
            slow = slow?.next
            fast = fast.next?.next
        }
        return fast != null
    }
}