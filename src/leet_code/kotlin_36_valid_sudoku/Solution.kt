package leet_code.kotlin_36_valid_sudoku

class Solution {
    fun isValidSudoku(board: Array<CharArray>): Boolean {
        val rows = Array(9) { mutableSetOf<Char>() }
        val cols = Array(9) { mutableSetOf<Char>() }
        val boxes = Array(9) { mutableSetOf<Char>() }
        board.forEachIndexed { i, row ->
            row.forEachIndexed { j, c ->
                if (c != '.') {
                    val boxIndex = (i / 3) * 3 + j / 3
                    if (!rows[i].add(c) || !cols[j].add(c) || !boxes[boxIndex].add(c)) {
                        return false
                    }
                }
            }
        }
        return true
    }
}