package leet_code.kotlin_71_simplify_path

class Solution {
    fun simplifyPath(path: String): String {
        val stack = mutableListOf<String>()
        for (token in path.split("/")) {
            when (token) {
                "", "." -> continue
                ".." -> stack.removeLastOrNull()
                else -> stack.add(token)
            }
        }
        return "/" + stack.joinToString("/")
    }
}
