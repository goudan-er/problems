/**
 * @author [gg]
 * @email [llyanwenyuan@gmail.com]
 * @create date 2019-02-16 14:24:52
 * @modify date 2019-02-16 14:24:52
 * @desc [https://www.geeksforgeeks.org/binary-heap/]
 */

// A C++ program to demonstrate common Binary Heap Operations
#include <algorithm>
#include <stdexcept>
#include <string>
#include <sstream>

// A class for Min Heap
class MinHeap {
private:
    int *harr;      // pointer to array of elements in heap
    int capacity;   // maximum possible size of min heap
    int heap_size;  // Current number of elements in min heap

public:
    // Constructor
    MinHeap(int capacity);
    MinHeap(int *arr, int n, int capacity);
    ~MinHeap()
    {
        delete[] harr;
        harr = nullptr;
    }

    int parent(int i) { return (i - 1) / 2; }

    // to get index of left child of node at index i
    int left(int i) { return (2 * i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2 * i + 2); }

    // to extract the root which is the minimum element
    int extractMin();

    // Update key value of key at index i to new_val
    void updateKey(int i, int new_val);

    // Returns the minimum key (key at root) from min heap
    int getMin();

    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key 'k'
    void insertKey(int k);

    // Check a heap is valid
    bool isValid();

    std::string to_string()
    {
        std::stringstream ss;
        ss << "[ ";
        for (int i = 0; i < heap_size; ++i) {
            ss << harr[i] << " ";
        }
        ss << "]";
        return ss.str();
    }

private:
    void percolateDown(int idx);
    void percolateUp(int idx);
};