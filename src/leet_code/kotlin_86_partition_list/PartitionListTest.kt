package leet_code.kotlin_86_partition_list

import leet_code.kotlin_data.ListNode
import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class PartitionListTest {
    @Test
    fun partition() {
        val instance = PartitionList()
        val input = fromArray(intArrayOf(1, 4, 3, 2, 5, 2))
        val expected = fromArray(intArrayOf(1, 2, 2, 4, 3, 5))
        val actual = instance.partition(input, 3)
        Assertions.assertEquals(expected, actual)
    }

    private fun fromArray(array: IntArray): ListNode? {
        if (array.isEmpty()) {
            return null
        }
        val head = ListNode(array[0])
        var current = head
        for (i in 1 until array.size) {
            current.next = ListNode(array[i])
            current = current.next!!
        }
        return head
    }
}
