package leet_code.kotlin_1233_remove_sub_folders_from_the_filesystem

class Trie {
    private val children = mutableMapOf<String, Trie>()
    private var isEnd = false

    fun insert(path: List<String>) {
        if (isEnd || path.isEmpty()) isEnd = true
        else children.getOrPut(path.first()) { Trie() }.insert(path.drop(1))
    }

    fun traverse(): List<String> {
        return children.flatMap { (folder, trie) ->
            if (trie.isEnd) listOf(folder)
            else trie.traverse().map { "$folder/$it" }
        }
    }
}

class Solution {
    fun removeSubfolders(folder: Array<String>): List<String> {
        val trie = Trie()
        folder.map { it.drop(1).split("/") }.forEach(trie::insert)
        return trie.traverse().map { "/$it" }
    }
}