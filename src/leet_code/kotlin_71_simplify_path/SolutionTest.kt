package leet_code.kotlin_71_simplify_path

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        Assertions.assertEquals("/home", Solution().simplifyPath("/home/"))
        Assertions.assertEquals("/", Solution().simplifyPath("/../"))
        Assertions.assertEquals("/home/foo", Solution().simplifyPath("/home//foo/"))
        Assertions.assertEquals("/c", Solution().simplifyPath("/a/./b/../../c/"))
        Assertions.assertEquals("/c", Solution().simplifyPath("/a/../../b/../c//.//"))
        Assertions.assertEquals("/a/b/c", Solution().simplifyPath("/a//b////c/d//././/.."))
    }
}
