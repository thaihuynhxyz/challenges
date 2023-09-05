package leet_code.kotlin_104_maximum_depth_of_binary_tree

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(3, instance.maxDepth(TreeNode(3).apply {
            left = TreeNode(9)
            right = TreeNode(20).apply {
                left = TreeNode(15)
                right = TreeNode(7)
            }
        }))
        Assertions.assertEquals(2, instance.maxDepth(TreeNode(1).apply {
            right = TreeNode(2)
        }))
        Assertions.assertEquals(4, instance.maxDepth(TreeNode(0).apply {
            left = TreeNode(0).apply {
                left = TreeNode(0)
            }
            right = TreeNode(0).apply {
                right = TreeNode(0).apply {
                    right = TreeNode(0)
                }
            }
        }))
    }
}
