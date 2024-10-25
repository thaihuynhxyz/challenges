package leet_code.kotlin_1233_remove_sub_folders_from_the_filesystem

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertLinesMatch(
            listOf("/a", "/c/d", "/c/f"),
            Solution().removeSubfolders(
                arrayOf("/a", "/a/b", "/c/d", "/c/d/e", "/c/f", "/c/f/g")
            )
        )

        Assertions.assertLinesMatch(
            listOf("/a"),
            Solution().removeSubfolders(
                arrayOf("/a", "/a/b/c", "/a/b/d")
            )
        )

        Assertions.assertLinesMatch(
            listOf("/a/b/c", "/a/b/ca", "/a/b/d"),
            Solution().removeSubfolders(
                arrayOf("/a/b/c", "/a/b/ca", "/a/b/d")
            )
        )
    }
}
