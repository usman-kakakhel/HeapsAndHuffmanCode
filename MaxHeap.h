/* *
* Title : Heaps and AVL Trees
* Author : Mian Usman Naeem Kakakhel
* Description : description of your code
*/

#ifndef __MAXHEAP_H
#define __MAXHEAP_H

#include <iostream>
#include <ctime>
#include <time.h>
#include <cmath>
#include <cstdlib>
using namespace std;

class MaxHeap {
public:
    static const int MAX_HEAP = 10000;
	MaxHeap();				// default constructor

	void insert ( int value ); // inserts integer into heap
    int peek () ; // returns the value of the max element
    int extractMax () ; // retrieves and removes the max element
    int size(); // returns the number of elements in the heap
    

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at 
					        // index root into a heap
private:
	int items[MAX_HEAP];	// array of heap items
	int  len;            	// number of heap items
};



#endif
