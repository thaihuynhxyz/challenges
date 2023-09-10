package leet_code.kotlin_data

abstract class DFS<T> {
    private val stack = mutableListOf<T>()
    private val visited = mutableSetOf<T>()

    fun solve(start: T, onVisit: (T) -> Unit = {}) {
        visited.add(start)
        stack.add(start)
        while (stack.isNotEmpty()) {
            val top = stack.removeLast()
            onVisit(top)

            for (node in children(top)) {
                if (visited.add(node)) {
                    push(node, top)
                }
            }
        }
    }

    protected open fun push(children: T, parent: T) {
        stack.add(children)
    }

    abstract fun children(input: T): List<T>
}

abstract class ParentDFS<T> : DFS<T>() {
    protected val parent = mutableMapOf<T, T>()

    override fun push(children: T, parent: T) {
        super.push(children, parent)
        this.parent[children] = parent
    }
}