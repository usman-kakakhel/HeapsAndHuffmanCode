/* *
* Title : Heaps and AVL Trees
* Author : Mian Usman Naeem Kakakhel
* Description : description of your code
*/

#ifndef __MINHEAP_H
#define __MINHEAP_H

#include <iostream>
#include <ctime>
#include <time.h>
#include <cmath>
#include <cstdlib>
using namespace std;

class MinHeap {
public:
    static const int MIN_HEAP = 10000;
	MinHeap();				// default constructor

	void insert ( int value ); // inserts integer into heap
    int peek (); // returns the value of the min element
    int extractMin (); // retrieves and removes the min element
    int size(); // returns the number of elements in the heap
    

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at 
					        // index root into a heap
private:
	int items[MIN_HEAP];	// array of heap items
	int  len;            	// number of heap items
};




#endif
