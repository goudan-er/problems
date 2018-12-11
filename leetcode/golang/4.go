package leetcode

func getUpperBound(nums []int, target int) int {
	l, r, ret := 0, len(nums)-1, len(nums)
	for l <= r {
		mid := (r-l)/2 + l
		if nums[mid] > target {
			ret = mid
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	return ret
}

func findKthNumber(k int, nums1 []int, nums2 []int) int {
	if len(nums1) == 0 {
		return nums2[k-1]
	}
	if len(nums2) == 0 {
		return nums1[k-1]
	}
	mid1 := (len(nums1) - 1) / 2
	idx2 := getUpperBound(nums2, nums1[mid1])
	cnt1, cnt2 := mid1, idx2
	if k == cnt1+cnt2+1 {
		return nums1[mid1]
	} else if k <= cnt1+cnt2 {
		return findKthNumber(k, nums1[0:mid1], nums2[0:idx2])
	} else {
		return findKthNumber(k-cnt1-cnt2-1, nums1[mid1+1:], nums2[idx2:])
	}
}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	total := len(nums1) + len(nums2)

	if total%2 == 0 {
		m1 := findKthNumber(total/2, nums1, nums2)
		m2 := findKthNumber(total/2+1, nums1, nums2)
		return 0.5 * float64(m1+m2)
	}

	return float64(findKthNumber(total/2+1, nums1, nums2))
}
