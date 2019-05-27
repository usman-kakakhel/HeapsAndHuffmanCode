/* *
* Title : Heaps and AVL Trees
* Author : Mian Usman Naeem Kakakhel
* Description : description of your code
*/


#include "HuffmanHeap.h"

HuffmanHeap::HuffmanHeap()
{
    len = 0;
}


void HuffmanHeap::insert(MinHeapNode* value)
{
    if (len >= HUFFMAN_HEAP)
        throw "heap is full";
    else
    {
        items[len] = value;

        // Trickle new item up to its proper position
        int place = len;
        int parent = (place - 1)/2;
        while ( (place > 0) && (items[place]->freq < items[parent]->freq) ) {
            MinHeapNode* temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
        ++len;
    }
    
}

void HuffmanHeap::heapRebuild(int root) {   
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < len ) {		
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find smaller child
		if ( (rightChild < len) && (items[rightChild]->freq < items[child]->freq) )
			child = rightChild; 	// index of smaller child

		// If root’s item is larger than smaller child, swap values
		if ( items[root]->freq > items[child]->freq ) {
			MinHeapNode* temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
    }
}


HuffmanHeap::MinHeapNode* HuffmanHeap::peek()
{
    if (len > 0)
        return items[0];
    else 
        throw "Heap does not have any element";
} // returns the value of the min element

HuffmanHeap::MinHeapNode* HuffmanHeap::extractMin()
{
    if (len > 0)
    {
        MinHeapNode* a = items[0];
		items[0] = items[--len];
		heapRebuild(0);
        return a;
    }
    else 
        throw "Heap does not have any element";
} // retrieves and removes the min element

int HuffmanHeap::size()
{
    return len;
} // returns the number of elements in the heap
