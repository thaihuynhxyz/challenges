package leet_code.kotlin_332_reconstruct_itinerary

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test

class SolutionTest {
    @Test
    fun test() {
        val solution = Solution()
        Assertions.assertEquals(
            listOf("JFK", "MUC", "LHR", "SFO", "SJC"),
            solution.findItinerary(
                listOf(
                    listOf("MUC", "LHR"),
                    listOf("JFK", "MUC"),
                    listOf("SFO", "SJC"),
                    listOf("LHR", "SFO")
                )
            )
        )
        Assertions.assertEquals(
            listOf("JFK", "ATL", "JFK", "SFO", "ATL", "SFO"),
            solution.findItinerary(
                listOf(
                    listOf("JFK", "SFO"),
                    listOf("JFK", "ATL"),
                    listOf("SFO", "ATL"),
                    listOf("ATL", "JFK"),
                    listOf("ATL", "SFO")
                )
            )
        )

        // [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
        Assertions.assertEquals(
            listOf("JFK", "NRT", "JFK", "KUL"),
            solution.findItinerary(
                listOf(
                    listOf("JFK", "KUL"),
                    listOf("JFK", "NRT"),
                    listOf("NRT", "JFK")
                )
            )
        )
    }
}
