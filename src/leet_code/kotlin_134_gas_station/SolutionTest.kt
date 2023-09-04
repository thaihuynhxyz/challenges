package leet_code.kotlin_134_gas_station

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertEquals(3, instance.canCompleteCircuit(intArrayOf(1, 2, 3, 4, 5), intArrayOf(3, 4, 5, 1, 2)))
        Assertions.assertEquals(-1, instance.canCompleteCircuit(intArrayOf(2, 3, 4), intArrayOf(3, 4, 3)))
    }
}
