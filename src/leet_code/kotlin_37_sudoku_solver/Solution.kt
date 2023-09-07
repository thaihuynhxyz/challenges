package leet_code.kotlin_37_sudoku_solver

class Solution {
    fun solveSudoku(board: Array<CharArray>) {
        val rows = Array(9) { BooleanArray(9) }
        val cols = Array(9) { BooleanArray(9) }
        val boxes = Array(9) { BooleanArray(9) }
        board.forEachIndexed { i, row ->
            row.forEachIndexed { j, c ->
                if (c != '.') {
                    val boxIndex = (i / 3) * 3 + j / 3
                    val charIndex = c - '1'
                    rows[i][charIndex] = true
                    cols[j][charIndex] = true
                    boxes[boxIndex][charIndex] = true
                }
            }
        }
        BackTracking<Candidate>().solve(Candidate(board, 0, rows, cols, boxes))
    }
}

data class Candidate(
    val data: Array<CharArray>,
    val index: Int,
    val rows: Array<BooleanArray>,
    val cols: Array<BooleanArray>,
    val boxes: Array<BooleanArray>,
    val commit: (() -> Unit)? = null,
    val rollback: (() -> Unit)? = null,
) : BackTracking.Companion.Candidate<Candidate> {

    override fun isAccept(): Boolean {
        return index == 81
    }

    override fun isReject(): Boolean {
        val (row, col, box) = rowColBox
        val c = data[row][col]
        val charIndex = c - '1'
        return c != '.' && (!rows[row][charIndex] || !cols[col][charIndex] || !boxes[box][charIndex])
    }

    override fun candidates(): List<Candidate> {
        val (row, col, box) = rowColBox
        val c = data[row][col]
        if (c != '.') return listOf(copy(index = index + 1, commit = null, rollback = null))

        val result = mutableListOf<Candidate>()
        for (num in 0 until 9) {
            result.add(copy(
                commit = {
                    rows[row][num] = rows[row][num] xor true
                    cols[col][num] = cols[col][num] xor true
                    boxes[box][num] = boxes[box][num] xor true
                    data[row][col] = '1' + num
                },
                rollback = {
                    rows[row][num] = rows[row][num] xor true
                    cols[col][num] = cols[col][num] xor true
                    boxes[box][num] = boxes[box][num] xor true
                    data[row][col] = '.'
                }
            ))
        }
        return result
    }

    override fun commit() {
        commit?.invoke()
    }

    override fun rollback() {
        rollback?.invoke()
    }

    private val rowColBox get() = Triple(index / 9, index % 9, index / 27 * 3 + index % 9 / 3)

    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (javaClass != other?.javaClass) return false

        other as Candidate

        if (!data.contentDeepEquals(other.data)) return false
        if (index != other.index) return false

        return true
    }

    override fun hashCode(): Int {
        var result = data.contentDeepHashCode()
        result = 31 * result + index
        return result
    }
}

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
