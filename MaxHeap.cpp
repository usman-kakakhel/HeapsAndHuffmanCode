/* *
* Title : Heaps and AVL Trees
* Author : Mian Usman Naeem Kakakhel
* Description : description of your code
*/


#include "MaxHeap.h"

MaxHeap::MaxHeap()
{
    len = 0;
}

void MaxHeap::insert(int value)
{
    if (len >= MAX_HEAP)
        throw "heap is full";
    else
    {
        items[len] = value;

        // Trickle new item up to its proper position
        int place = len;
        int parent = (place - 1)/2;
        while ( (place > 0) && (items[place] > items[parent]) ) {
            int temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
        ++len;
    }
    
}

void MaxHeap::heapRebuild(int root) {   
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < len ) {		
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < len) && (items[rightChild] > items[child]) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( items[root] < items[child] ) {
			int temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
    }
}


int MaxHeap::peek()
{
    if (len > 0)
        return items[0];
    else 
        throw "Heap does not have any element";
} // returns the value of the max element

int MaxHeap::extractMax()
{
    if (len > 0)
    {
        int a = items[0];
		items[0] = items[--len];
		heapRebuild(0);
        return a;
    }
    else 
        throw "Heap does not have any element";
} // retrieves and removes the max element

int MaxHeap::size()
{
    return len;
} // returns the number of elements in the heap
