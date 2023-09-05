package leet_code.kotlin_104_maximum_depth_of_binary_tree

/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 */
class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

class Solution {
    fun maxDepth(root: TreeNode?): Int {
        return root?.let { 1 + maxOf(maxDepth(root.left), maxDepth(root.right)) } ?: 0
    }
}