package leetcode

func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	next := head.Next
	nextHead := next.Next
	next.Next = head
	head.Next = swapPairs(nextHead)
	return next
}
