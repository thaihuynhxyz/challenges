package leet_code.kotlin_1971_find_if_path_exists_in_graph

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val instance = Solution()
        Assertions.assertTrue(
            instance.validPath(
                3,
                arrayOf(intArrayOf(0, 1), intArrayOf(1, 2), intArrayOf(2, 0)),
                0,
                2
            )
        )
        Assertions.assertFalse(
            instance.validPath(
                6,
                arrayOf(intArrayOf(0, 1), intArrayOf(0, 2), intArrayOf(3, 5), intArrayOf(5, 4), intArrayOf(4, 3)),
                0,
                5
            )
        )
    }
}
