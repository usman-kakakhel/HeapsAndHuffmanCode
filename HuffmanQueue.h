/* *
* Title : Heaps and AVL Trees
* Author : Mian Usman Naeem Kakakhel
* Description : description of your code
*/

#ifndef __HUFFMANQUEUE_H
#define __HUFFMANQUEUE_H

#include "HuffmanHeap.h"

class HuffmanQueue {

    private:
    HuffmanHeap heap;

    public:
        
        HuffmanQueue();				// default constructor
        bool isEmpty();
        int size();
        void enqueue(HuffmanHeap::MinHeapNode* value);
        HuffmanHeap::MinHeapNode* dequeue();

};




#endif
