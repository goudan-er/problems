/**
 * @author [gg]
 * @email [llyanwenyuan@gmail.com]
 * @create date 2019-02-16 15:41:33
 * @modify date 2019-02-16 15:41:33
 * @desc [min heap implementation]
 */

#include "min_heap.h"

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

/*** core ***/
MinHeap::MinHeap(int *arr, int n, int cap)
{
    heap_size = n;
    capacity = cap;
    harr = new int[cap];
    memcpy(harr, arr, sizeof(int) * n);
    for (int i = parent(heap_size - 1); i >= 0; --i) {
        percolateDown(i);
    }
}

void MinHeap::insertKey(int k)
{
    if (heap_size == capacity) {
        throw std::runtime_error("op is invalid");
    }

    ++heap_size;
    int pos = heap_size - 1;
    harr[pos] = k;
    percolateUp(pos);
}

int MinHeap::getMin()
{
    if (heap_size == 0) {
        throw std::runtime_error("op is invalid");
    }

    return harr[0];
}

int MinHeap::extractMin()
{
    if (heap_size == 0) {
        throw std::runtime_error("op is invalid");
    }

    int min_value = getMin();
    std::swap(harr[0], harr[heap_size - 1]);
    --heap_size;
    percolateDown(0);
    return min_value;
}

void MinHeap::deleteKey(int k)
{
    if (k < 0 || k >= heap_size) {
        throw std::runtime_error("op is invalid");
    }

    int last_value = harr[heap_size - 1];
    --heap_size;
    if (heap_size > 0) updateKey(k, last_value);
}

void MinHeap::updateKey(int k, int new_val)
{
    if (k >= heap_size) {
        throw std::runtime_error("op is invalid");
    }

    harr[k] = new_val;
    int p = parent(k);
    if (k == 0 || harr[k] > harr[p]) {
        percolateDown(k);
    } else {
        percolateUp(k);
    }
}

void MinHeap::percolateDown(int idx)
{
    for (int child = left(idx); child < heap_size;
         idx = child, child = left(idx)) {
        if (child + 1 < heap_size && harr[child] > harr[child + 1])
            ++child;                         // right is smaller
        if (harr[idx] < harr[child]) break;  // adjust finish
        std::swap(harr[idx], harr[child]);
    }
}

void MinHeap::percolateUp(int idx)
{
    for (int p = parent(idx); idx != 0; idx = p, p = parent(idx)) {
        if (harr[p] < harr[idx]) break;  // adjust finish
        std::swap(harr[p], harr[idx]);
    }
}

bool MinHeap::isValid()
{
    for (int i = 0; i <= parent(heap_size - 1); ++i) {
        int lchild = left(i), rchild = right(i);
        if (harr[i] > harr[lchild]) return false;
        if (rchild < heap_size && harr[i] > harr[rchild]) return false;
    }
    return true;
}