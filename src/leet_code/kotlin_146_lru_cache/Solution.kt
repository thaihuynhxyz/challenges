package leet_code.kotlin_146_lru_cache

class LRUCache(private val capacity: Int): LinkedHashMap<Int, Int>(capacity, 0.75f, true) {
    override fun removeEldestEntry(eldest: MutableMap.MutableEntry<Int, Int>?): Boolean {
        return size > capacity
    }

    override fun get(key: Int): Int {
        return super.get(key) ?: -1
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */