package leetcode

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head == nil {
		return head
	}

	slow, fast := head, head
	for i := 0; i < n; i++ {
		fast = fast.Next
	}

	guard := ListNode{Next: head}
	preSlow := &guard
	for fast != nil {
		fast = fast.Next
		preSlow = slow
		slow = slow.Next
	}

	if slow != nil {
		preSlow.Next = slow.Next
		slow.Next = nil
	}

	return guard.Next
}
