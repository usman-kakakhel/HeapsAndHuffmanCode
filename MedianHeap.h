/* *
* Title : Heaps and AVL Trees
* Author : Mian Usman Naeem Kakakhel
* Description : description of your code
*/

#ifndef __MEDIANHEAP_H
#define __MEDIANHEAP_H

#include "MaxHeap.h"
#include "MinHeap.h"
using namespace std;

class MedianHeap {
public:
	MedianHeap();				// default constructor

	void insert ( int value ); // inserts integer into madianHeap
    int findMedian ();
    

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at 
					        // index root into a heap
private:
    MaxHeap max_Heap;
    MinHeap min_Heap;
	int  len;            	// number of heap items
};



#endif
