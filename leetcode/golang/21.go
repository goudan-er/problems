package leetcode

type ListNode struct {
	Val  int
	Next *ListNode
}

// func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
// 	if l1 == nil {
// 		return l2
// 	} else if l2 == nil {
// 		return l1
// 	} else {
// 		var head *ListNode
// 		if l1.Val <= l2.Val {
// 			head = l1
// 			head.Next = mergeTwoLists(l1.Next, l2)
// 		} else {
// 			head = l2
// 			head.Next = mergeTwoLists(l1, l2.Next)
// 		}
// 		return head
// 	}
// }

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	} else if l2 == nil {
		return l1
	} else {
		var head *ListNode
		if l1.Val <= l2.Val {
			head = l1
			head.Next = mergeTwoLists(l1.Next, l2)
		} else {
			head = l2
			head.Next = mergeTwoLists(l1, l2.Next)
		}
		return head
	}
}
