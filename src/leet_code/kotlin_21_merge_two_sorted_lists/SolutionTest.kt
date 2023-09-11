package leet_code.kotlin_21_merge_two_sorted_lists

import leet_code.kotlin_data.ListNode
import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertEquals(
            ListNode(1).apply {
                next = ListNode(1).apply {
                    next = ListNode(2).apply {
                        next = ListNode(3).apply {
                            next = ListNode(4).apply {
                                next = ListNode(4)
                            }
                        }
                    }
                }
            },
            Solution().mergeTwoLists(
                ListNode(1).apply {
                    next = ListNode(2).apply {
                        next = ListNode(4)
                    }
                },
                ListNode(1).apply {
                    next = ListNode(3).apply {
                        next = ListNode(4)
                    }
                }
            )
        )

        Assertions.assertEquals(
            null,
            Solution().mergeTwoLists(
                null,
                null
            )
        )

        Assertions.assertEquals(
            ListNode(0),
            Solution().mergeTwoLists(
                null,
                ListNode(0)
            )
        )
    }
}
