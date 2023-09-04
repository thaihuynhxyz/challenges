package leet_code.kotlin_380_insert_delete_getrandom_o1

class RandomizedSet {

    private val map = HashMap<Int, Int>()
    private val list = ArrayList<Int>()
    private val random = java.util.Random()

    fun insert(`val`: Int): Boolean {
        if (map.containsKey(`val`)) return false
        map[`val`] = list.size
        list.add(`val`)
        return true
    }

    fun remove(`val`: Int): Boolean {
        if (!map.containsKey(`val`)) return false
        val index = map[`val`]!!
        val last = list[list.size - 1]
        list[index] = last
        map[last] = index
        list.removeAt(list.size - 1)
        map.remove(`val`)
        return true
    }

    fun getRandom(): Int {
        return list[random.nextInt(list.size)]
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = RandomizedSet()
 * var param_1 = obj.insert(`val`)
 * var param_2 = obj.remove(`val`)
 * var param_3 = obj.getRandom()
 */