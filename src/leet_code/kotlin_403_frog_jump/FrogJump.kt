package leet_code.kotlin_403_frog_jump

class FrogJump {
    fun canCross(stones: IntArray): Boolean {
        val map = HashMap<Int, HashSet<Int>>()
        for (stone in stones) {
            map[stone] = HashSet()
        }
        map[0]!!.add(1)
        var steps : HashSet<Int>
        var nextStone : Int
        for (stone in stones) {
            steps = map[stone]!!
            for (step in steps) {
                nextStone = stone + step
                if (nextStone == stones[stones.size - 1]) {
                    return true
                }
                map[nextStone]?.let {
                    it.add(step)
                    if (step - 1 > 0) {
                        it.add(step - 1)
                    }
                    it.add(step + 1)
                }
            }
        }
        return false
    }
}
