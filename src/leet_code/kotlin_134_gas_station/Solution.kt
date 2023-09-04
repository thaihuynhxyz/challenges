package leet_code.kotlin_134_gas_station

class Solution {
    fun canCompleteCircuit(gas: IntArray, cost: IntArray): Int {
        var total = 0
        var tank = 0
        var start = 0
        for (i in gas.indices) {
            val consume = gas[i] - cost[i]
            tank += consume
            if (tank < 0) {
                start = i + 1
                tank = 0
            }
            total += consume
        }
        return if (total < 0) -1 else start
    }
}