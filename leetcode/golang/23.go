package leetcode

// import "math"

// func getNextHead(heads []*ListNode) (int, *ListNode) {
// 	var minimum = int(math.MaxInt32)
// 	var ret *ListNode
// 	var retIdx int
// 	for idx, head := range heads {
// 		if head != nil && head.Val < minimum {
// 			ret = head
// 			retIdx = idx
// 			minimum = head.Val
// 		}
// 	}
// 	return retIdx, ret
// }

// func mergeKLists(lists []*ListNode) *ListNode {
// 	var retHead ListNode
// 	cur := &retHead
// 	for {
// 		idx, next := getNextHead(lists)
// 		if next == nil {
// 			break
// 		}
// 		cur.Next = next
// 		cur = cur.Next
// 		if lists[idx].Next == nil {
// 			lists = append(lists[:idx], lists[idx+1:]...)
// 		} else {
// 			lists[idx] = lists[idx].Next
// 		}
// 	}
// 	return retHead.Next
// }

func mergeKLists(lists []*ListNode) *ListNode {
	l := len(lists)
	if l == 0 {
		return nil
	} else if l == 1 {
		return lists[0]
	} else if l == 2 {
		return mergeTwoLists(lists[0], lists[1])
	}
	return mergeTwoLists(mergeKLists(lists[0:l/2]), mergeKLists(lists[l/2:]))
}

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
