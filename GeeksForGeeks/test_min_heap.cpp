#include "min_heap.h"

#include <assert.h>
#include <iostream>

using namespace std;

// Driver program to test above functions
int main()
{
    int arr[] = {30, 25, 20, 10, 1, 2, 5, 8, 60, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    MinHeap h(arr, n, 100);
    cout << h.getMin() << endl;
    cout << h.to_string() << endl;
    assert(h.isValid());

    h.deleteKey(2);
    cout << h.to_string() << endl;
    assert(h.isValid());

    h.deleteKey(0);
    cout << h.to_string() << endl;
    assert(h.isValid());

    h.insertKey(8);
    h.insertKey(10);
    cout << h.extractMin() << endl;
    cout << h.getMin() << endl;
    cout << h.to_string() << endl;
    assert(h.isValid());

    h.updateKey(1, 5);
    cout << h.getMin() << endl;
    cout << h.to_string() << endl;
    assert(h.isValid());

    cout << h.extractMin() << endl;
    cout << h.extractMin() << endl;
    cout << h.to_string() << endl;
    assert(h.isValid());

    h.updateKey(0, 50);
    cout << h.extractMin() << endl;
    cout << h.to_string() << endl;
    assert(h.isValid());

    h.insertKey(10);
    h.insertKey(20);
    h.updateKey(1, 3);
    cout << h.to_string() << endl;
    cout << h.extractMin() << endl;
    cout << h.extractMin() << endl;
    cout << h.to_string() << endl;
    assert(h.isValid());

    h.insertKey(6);
    h.deleteKey(0);
    cout << h.to_string() << endl;
    assert(h.isValid());

    return 0;
}