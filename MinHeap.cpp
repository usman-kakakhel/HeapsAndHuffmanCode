/* *
* Title : Heaps and AVL Trees
* Author : Mian Usman Naeem Kakakhel
* Description : description of your code
*/


#include "MinHeap.h"

MinHeap::MinHeap()
{
    len = 0;
}

void MinHeap::insert(int value)
{
    if (len >= MIN_HEAP)
        throw "heap is full";
    else
    {
        items[len] = value;

        // Trickle new item up to its proper position
        int place = len;
        int parent = (place - 1)/2;
        while ( (place > 0) && (items[place] < items[parent]) ) {
            int temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
        ++len;
    }
    
}

void MinHeap::heapRebuild(int root) {   
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < len ) {		
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find smaller child
		if ( (rightChild < len) && (items[rightChild] < items[child]) )
			child = rightChild; 	// index of smaller child

		// If root’s item is larger than smaller child, swap values
		if ( items[root] > items[child] ) {
			int temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
    }
}


int MinHeap::peek()
{
    if (len > 0)
        return items[0];
    else 
        throw "Heap does not have any element";
} // returns the value of the min element

int MinHeap::extractMin()
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
} // retrieves and removes the min element

int MinHeap::size()
{
    return len;
} // returns the number of elements in the heap
