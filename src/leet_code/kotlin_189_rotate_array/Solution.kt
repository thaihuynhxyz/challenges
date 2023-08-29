package leet_code.kotlin_189_rotate_array

class Solution {
    fun rotate(nums: IntArray, k: Int) {
        var size = nums.size
        var kVar = k % size
        while (size > 0 && kVar > 0) {
            for (j in 0 until kVar) {
                val swapIndex = size - kVar - 1
                if (swapIndex >= 0) {
                    nums.swap(--size, swapIndex)
                } else {
                    kVar -= j
                    break
                }
            }
            kVar %= size
        }
    }
}

fun IntArray.swap(index1: Int, index2: Int){
    this[index1] = this[index2].also { this[index2] = this[index1] }
}
