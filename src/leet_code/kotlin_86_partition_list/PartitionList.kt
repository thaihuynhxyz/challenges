package leet_code.kotlin_86_partition_list

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
    fun partition(head: ListNode?, x: Int): ListNode? {
        var head1: ListNode? = null
        var head2: ListNode? = null
        var tail1: ListNode? = null
        var tail2: ListNode? = null
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

class ListNode(var `val`: Int) {
    var next: ListNode? = null

    override fun equals(other: Any?): Boolean {
        if (other !is ListNode) {
            return false
        }
        var currentThis: ListNode? = this
        var currentOther: ListNode? = other
        while (currentThis != null && currentOther != null) {
            if (currentThis.`val` != currentOther.`val`) {
                return false
            }
            currentThis = currentThis.next
            currentOther = currentOther.next
        }
        return !(currentThis != null || currentOther != null)
    }

    override fun hashCode(): Int {
        var result = `val`
        result = 31 * result + (next?.hashCode() ?: 0)
        return result
    }
}