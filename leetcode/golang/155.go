package leetcode

import (
	"math"
)

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

type MinStack struct {
	numsStk []int
	minStk  []int
	sz      int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{[]int{}, []int{}, 0}
}

func (this *MinStack) Push(x int) {
	this.numsStk = append(this.numsStk, x)
	this.minStk = append(this.minStk, min(this.GetMin(), x))
	this.sz++
}

func (this *MinStack) Pop() {
	if this.sz > 0 {
		this.numsStk = this.numsStk[0 : this.sz-1]
		this.minStk = this.minStk[0 : this.sz-1]
		this.sz--
	}
}

func (this *MinStack) Top() int {
	if this.sz > 0 {
		return this.numsStk[this.sz-1]
	}
	return math.MinInt32
}

func (this *MinStack) GetMin() int {
	if this.sz > 0 {
		return this.minStk[this.sz-1]
	}
	return math.MaxInt32
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
