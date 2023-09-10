package leet_code.kotlin_841_keys_and_rooms

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertEquals(
            true,
            Solution().canVisitAllRooms(
                listOf(
                    listOf(1),
                    listOf(2),
                    listOf(3),
                    listOf()
                )
            )
        )
        Assertions.assertEquals(
            false,
            Solution().canVisitAllRooms(
                listOf(
                    listOf(1, 3),
                    listOf(3, 0, 1),
                    listOf(2),
                    listOf(0)
                )
            )
        )
    }
}
