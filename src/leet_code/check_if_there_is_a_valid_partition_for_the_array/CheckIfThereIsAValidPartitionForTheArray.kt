package leet_code.check_if_there_is_a_valid_partition_for_the_array

class CheckIfThereIsAValidPartitionForTheArray {
    fun validPartition(nums: IntArray): Boolean {
        val dp = BooleanArray(nums.size)
        dp[0] = true
        for (i in nums.indices) {
            if (nums.size - i < 2) return false
            if (dp[i]) {
                if (nums.size - i == 3 && isGood(nums.sliceArray(i until nums.size))) return true
                if (nums.size - i == 2) return isGood(nums.sliceArray(i until nums.size))
                if (isGood(nums.sliceArray(i until i + 2))) dp[i + 2] = true
                if (isGood(nums.sliceArray(i until i + 3))) dp[i + 3] = true
            }
        }
        return false
    }

    private fun isGood(nums: IntArray): Boolean {
        if (nums.size == 2 && nums[0] == nums[1]) return true
        if (nums.size == 3 && nums[0] == nums[1] && nums[1] == nums[2]) return true
        if (nums.size == 3 && nums[1] == nums[0] + 1 && nums[2] == nums[1] + 1) return true
        return false
    }
}