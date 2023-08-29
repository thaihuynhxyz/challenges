package leet_code.kotlin_2483_minimum_penalty_for_a_shop

class Solution {
    fun bestClosingTime(customers: String): Int {
        var yCount = customers.count { it == 'Y' }
        var nCount = 0
        var penalty = yCount
        var res = 0
        for (i in customers.indices) {
            when (customers[i]) {
                'Y' -> yCount--
                'N' -> nCount++
            }
            if (penalty > yCount + nCount) {
                penalty = yCount + nCount
                res = i + 1
            }
        }
        return res
    }
}
