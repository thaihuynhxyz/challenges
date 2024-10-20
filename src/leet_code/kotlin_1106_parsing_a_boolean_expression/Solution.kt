package leet_code.kotlin_1106_parsing_a_boolean_expression

class Solution {
    fun parseBoolExpr(expression: String): Boolean {
        val stack = mutableListOf<Char>()
        for (c in expression) {
            if (c == ')') {
                val seen = mutableSetOf<Char>()
                while (stack.last() != '(') {
                    seen.add(stack.removeLast())
                }
                stack.removeLast()  // remove '('
                when (stack.removeLast()) { // remove operator
                    '&' -> stack.add(if (seen.contains('f')) 'f' else 't')
                    '|' -> stack.add(if (seen.contains('t')) 't' else 'f')
                    '!' -> stack.add(if (seen.contains('t')) 'f' else 't')
                }
            } else if (c != ',') {
                stack.add(c)
            }
        }
        return stack.single() == 't'
    }
}
