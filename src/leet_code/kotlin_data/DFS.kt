package leet_code.kotlin_data

abstract class DSF<T> {
    fun solve(start: T, onVisit: (T) -> Unit = {}) {
        val stack = mutableListOf<T>()
        val visited = mutableSetOf<T>()
        stack.add(start)
        while (stack.isNotEmpty()) {
            val top = stack.removeLast()
            onVisit(top)

            for (node in children(top)) {
                if (visited.add(node)) {
                    stack.add(node)
                }
            }
        }
    }

    abstract fun children(input: T): List<T>
}