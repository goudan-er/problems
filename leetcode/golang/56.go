package leetcode

import (
	"sort"
)

type Intervals []Interval

func (intervals Intervals) Len() int {
	return len(intervals)
}

func (intervals Intervals) Swap(i, j int) {
	intervals[i], intervals[j] = intervals[j], intervals[i]
}

func (intervals Intervals) Less(i, j int) bool {
	if intervals[i].Start < intervals[j].Start {
		return true
	} else if intervals[i].Start == intervals[j].Start && intervals[i].End < intervals[i].End {
		return true
	} else {
		return false
	}
}

func merge(intervals []Interval) []Interval {
	ret := []Interval{}
	sz := len(intervals)
	if sz == 0 {
		return ret
	}
	sort.Sort(Intervals(intervals))
	preEle := intervals[0]
	for i := 1; i < sz; i++ {
		ele := intervals[i]
		if ele.Start > preEle.End {
			ret = append(ret, preEle)
			preEle = ele
		} else if ele.End > preEle.End {
			preEle.End = ele.End
		}
	}
	ret = append(ret, preEle)
	return ret
}
