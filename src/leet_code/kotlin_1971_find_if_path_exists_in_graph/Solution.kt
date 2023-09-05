package leet_code.kotlin_1971_find_if_path_exists_in_graph

class Solution {
    fun validPath(n: Int, edges: Array<IntArray>, source: Int, destination: Int): Boolean {
        val graph = hashMapOf<Int, List<Int>>().also {
            for (edge in edges) {
                it[edge[0]] = it.getOrDefault(edge[0], listOf()).plus(edge[1])
                it[edge[1]] = it.getOrDefault(edge[1], listOf()).plus(edge[0])
            }
        }
        return graph.dfsFrom(source) { it == destination }
    }

    private inline fun <T> Map<T, List<T>>.dfsFrom(source: T, predicate: (T) -> Boolean): Boolean {
        val visited = hashSetOf<T>()
        val stack = mutableListOf<T>().apply { add(source) }
        while (stack.isNotEmpty()) {
            val node = stack.removeLast()
            if (predicate(node)) {
                return true
            }
            if (!visited.add(node)) continue
            for (neighbor in this[node]!!) {
                if (!visited.contains(neighbor)) {
                    stack.add(neighbor)
                }
            }
        }
        return false
    }
}