package leet_code.kotlin_951_flip_equivalent_binary_trees

/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

class Solution {
    fun flipEquiv(root1: TreeNode?, root2: TreeNode?): Boolean {
        return when {
            root1 == null && root2 == null -> true
            root1 == null || root2 == null || root1.`val` != root2.`val` -> false
            else -> (flipEquiv(root1.left, root2.right) && flipEquiv(root1.right, root2.left)) ||
                    (flipEquiv(root1.left, root2.left) && flipEquiv(root1.right, root2.right))
        }
    }
}