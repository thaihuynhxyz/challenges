package leet_code.kotlin_data

interface DFS<T> {
    val stack: MutableList<T>
    val visited: MutableSet<T>

    fun solve(start: T, onVisit: (T) -> Unit = {}) {
        visited.add(start)
        stack.add(start)
        dfs(start, onVisit)
    }

    fun dfs(start: T, onVisit: (T) -> Unit = {})

    fun push(children: T, parent: T) {
        stack.add(children)
    }

    fun canVisit(node: T) = visited.add(node)

    fun children(input: T): MutableList<T>?
}

abstract class PreOrderDFS<T> : DFS<T> {
    override val stack: MutableList<T> = mutableListOf()
    override val visited: MutableSet<T> = mutableSetOf()

    override fun dfs(start: T, onVisit: (T) -> Unit) {
        while (stack.isNotEmpty()) {
            stack.removeLast()?.let { top ->
                onVisit(top)
                children(top)?.let {
                    for (node in it) {
                        if (canVisit(node)) {
                            push(node, top)
                        }
                    }
                }
            }
        }
    }
}

abstract class PostOrderDFS<T> : DFS<T> {
    override val stack: MutableList<T> = mutableListOf()
    override val visited: MutableSet<T> = mutableSetOf()

    override fun dfs(start: T, onVisit: (T) -> Unit) {
        while (stack.isNotEmpty()) {
            while (children(stack.last())?.isNotEmpty() == true) {
                stack.last().let { parent ->
                    if (canVisit(children(parent)!!.last())) {
                        push(children(parent)!!.removeLast(), parent)
                    }
                }
            }
            onVisit(stack.removeLast())
        }
    }
}

interface ParentDFS<T> : DFS<T> {
    val parent: MutableMap<T, T>

    override fun push(children: T, parent: T) {
        super.push(children, parent)
        this.parent[children] = parent
    }
}