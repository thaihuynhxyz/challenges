package leet_code.kotlin_725_split_linked_list_in_parts

/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 */
class ListNode(var `val`: Int) {
    var next: ListNode? = null

    override fun equals(other: Any?): Boolean {
        return `val` == (other as ListNode).`val` && next == other.next
    }

    override fun hashCode(): Int {
        var result = `val`
        result = 31 * result + (next?.hashCode() ?: 0)
        return result
    }
}

class Solution {
    fun splitListToParts(head: ListNode?, k: Int): Array<ListNode?> {
        val result = Array<ListNode?>(k) { null }
        var size = 0
        var node = head
        while (node != null) {
            node = node.next
            ++size
        }
        node = head
        for (i in 0 until k) {
            result[i] = node
            val partSize = size / k + if (i < size % k) 1 else 0
            var tail = node
            for (j in 0 until partSize) {
                tail = node
                node = node?.next
            }
            tail?.next = null
        }
        return result
    }
}
