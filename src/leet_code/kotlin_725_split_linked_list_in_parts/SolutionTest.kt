package leet_code.kotlin_725_split_linked_list_in_parts

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertArrayEquals(
            arrayOf(
                ListNode(1),
                ListNode(2),
                ListNode(3),
                null,
                null
            ),
            instance.splitListToParts(ListNode(1).apply {
                next = ListNode(2).apply {
                    next = ListNode(3)
                }
            }, 5)
        )
        Assertions.assertArrayEquals(
            arrayOf(
                ListNode(1).apply {
                    next = ListNode(2).apply {
                        next = ListNode(3).apply {
                            next = ListNode(4)
                        }
                    }
                },
                ListNode(5).apply {
                    next = ListNode(6).apply {
                        next = ListNode(7)
                    }
                },
                ListNode(8).apply {
                    next = ListNode(9).apply {
                        next = ListNode(10)
                    }
                }
            ),
            instance.splitListToParts(ListNode(1).apply {
                next = ListNode(2).apply {
                    next = ListNode(3).apply {
                        next = ListNode(4).apply {
                            next = ListNode(5).apply {
                                next = ListNode(6).apply {
                                    next = ListNode(7).apply {
                                        next = ListNode(8).apply {
                                            next = ListNode(9).apply {
                                                next = ListNode(10)
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }, 3)
        )
    }
}
