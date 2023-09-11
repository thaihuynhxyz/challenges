package leet_code.kotlin_1282_group_the_people_given_the_group_size_they_belong_to

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertEquals(
            listOf(listOf(0, 1, 2), listOf(3, 4, 6), listOf(5)),
            Solution().groupThePeople(intArrayOf(3, 3, 3, 3, 3, 1, 3))
        )
        Assertions.assertEquals(
            listOf(listOf(0, 5), listOf(1), listOf(2, 3, 4)),
            Solution().groupThePeople(intArrayOf(2, 1, 3, 3, 3, 2))
        )
    }
}
