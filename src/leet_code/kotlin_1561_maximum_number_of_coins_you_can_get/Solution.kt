package leet_code.kotlin_1561_maximum_number_of_coins_you_can_get

class Solution {
    fun maxCoins(piles: IntArray): Int {
        piles.sort()
        var ans = 0
        var i = piles.size - 2
        var j = 0
        while (j < i) {
            ans += piles[i]
            i -= 2
            j++
        }
        return ans
    }
}
