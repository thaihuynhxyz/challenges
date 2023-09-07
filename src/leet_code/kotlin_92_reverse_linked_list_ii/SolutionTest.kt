package leet_code.kotlin_92_reverse_linked_list_ii

import leet_code.kotlin_data.ListNode
import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(
            ListNode(1).apply {
                next = ListNode(4).apply {
                    next = ListNode(3).apply {
                        next = ListNode(2).apply {
                            next = ListNode(5)
                        }
                    }
                }
            },
            instance.reverseBetween(
                ListNode(1).apply {
                    next = ListNode(2).apply {
                        next = ListNode(3).apply {
                            next = ListNode(4).apply {
                                next = ListNode(5)
                            }
                        }
                    }
                },
                2,
                4
            )
        )

        Assertions.assertEquals(
            ListNode(5),
            instance.reverseBetween(ListNode(5), 1, 1)
        )
    }
}
