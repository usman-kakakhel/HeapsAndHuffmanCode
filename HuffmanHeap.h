/* *
* Title : Heaps and AVL Trees
* Author : Mian Usman Naeem Kakakhel
* Description : description of your code
*/

#ifndef __HUFFMANHEAP_H
#define __HUFFMANHEAP_H

#include <iostream>
#include <ctime>
#include <time.h>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class HuffmanHeap {
    static const int HUFFMAN_HEAP = 128;

    friend class HuffmanQueue;
    friend class HuffmanCode;

    public:
        struct MinHeapNode
        {
            char character ; // An input character
            int freq ; // Frequency of the character
            MinHeapNode * left , * right ; // Left and right child
        };
        
        HuffmanHeap();				// default constructor

        void insert ( MinHeapNode* value ); // inserts integer into heap
        MinHeapNode* peek (); // returns the value of the min element
        MinHeapNode* extractMin (); // retrieves and removes the min element
        int size(); // returns the number of elements in the heap

    private:
	MinHeapNode* items[HUFFMAN_HEAP];	// array of heap items
	int  len;            	// number of heap items

    
        

    protected:
        void heapRebuild(int root);		// Converts the semiheap rooted at 
                                        // index root into a heap

};




#endif
