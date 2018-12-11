package leetcode

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{}
	cur := head
	flag := 0
	for l1 != nil || l2 != nil || flag > 0 {
		sum := flag
		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}
		cur.Next = &ListNode{Val: sum % 10}
		flag = sum / 10
		cur = cur.Next
	}
	return head.Next
}
