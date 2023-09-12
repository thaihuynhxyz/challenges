package leet_code.kotlin_data

class ListNode<T>(var `val`: T) {
    var next: ListNode<T>? = null
    var prev: ListNode<T>? = null

    override fun equals(other: Any?): Boolean {
        return `val` == (other as ListNode<*>?)?.`val` && next == other?.next && prev == other?.prev
    }

    override fun hashCode(): Int {
        var result = `val`?.hashCode() ?: 0
        result = 31 * result + (next?.hashCode() ?: 0)
        result = 31 * result + (prev?.hashCode() ?: 0)
        return result
    }
}