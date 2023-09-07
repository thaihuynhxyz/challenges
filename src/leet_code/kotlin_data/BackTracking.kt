package leet_code.kotlin_data

class BackTracking<T : BackTracking.Companion.Candidate<T>> {

    fun solve(candidate: T): Boolean {
        return when {
            candidate.isAccept() -> true
            candidate.isReject() -> false
            else -> {
                for (c in candidate.candidates()) {
                    c.commit()
                    if (solve(c)) return true
                    c.rollback()
                }
                false
            }
        }
    }

    companion object {
        interface Candidate<T> {
            fun isReject(): Boolean

            fun isAccept(): Boolean

            fun commit()

            fun rollback()

            fun candidates(): List<T>
        }
    }
}