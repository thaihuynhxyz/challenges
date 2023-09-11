package leet_code.kotlin_1282_group_the_people_given_the_group_size_they_belong_to

class Solution {
    fun groupThePeople(groupSizes: IntArray): List<List<Int>> {
        val map = mutableMapOf<Int, MutableList<Int>>()
        for (i in groupSizes.indices) {
            map.getOrPut(groupSizes[i]) { mutableListOf() }.add(i)
        }
        val ans = mutableListOf<List<Int>>()
        for (entry in map) {
            val size = entry.key
            val list = entry.value
            for (i in list.indices step size) {
                ans.add(list.subList(i, i + size))
            }
        }
        return ans
    }
}