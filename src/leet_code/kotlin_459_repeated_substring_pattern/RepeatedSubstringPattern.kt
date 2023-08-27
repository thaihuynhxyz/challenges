package leet_code.kotlin_459_repeated_substring_pattern

class RepeatedSubstringPattern {
    fun repeatedSubstringPattern(s: String): Boolean {
        val n = s.length
        for (i in 1..n / 2) {
            if (n % i == 0) {
                val sub = s.substring(0, i)
                var j = i
                while (j < n) {
                    if (s.substring(j, j + i) != sub) {
                        break
                    }
                    j += i
                }
                if (j == n) {
                    return true
                }
            }
        }
        return false
    }

    // Using KMP
    fun repeatedSubstringPattern2(s: String): Boolean {
        val n = s.length
        val lps = IntArray(n)
        var i = 1
        var len = 0
        while (i < n) {
            val si = s[i]
            val slen = s[len]
            if (si == slen) {   // Set match case
                len++
                lps[i] = len
                i++
            } else {
                if (len != 0) { // Reset to the len - 1 case
                    len = lps[len - 1]
                } else {    // Set mismatch case
                    lps[i] = 0
                    i++
                }
            }
        }
        return lps[n - 1] > 0 && n % (n - lps[n - 1]) == 0
    }
}
