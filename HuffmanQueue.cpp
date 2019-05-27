/* *
* Title : Heaps and AVL Trees
* Author : Mian Usman Naeem Kakakhel
* Description : description of your code
*/

#include "HuffmanQueue.h"


HuffmanQueue::HuffmanQueue()
{}

bool HuffmanQueue::isEmpty()
{
    if (heap.size() == 0)
        return true;
    else 
        return false;
}


void HuffmanQueue::enqueue(HuffmanHeap::MinHeapNode* value)
{
    heap.insert(value);
}

HuffmanHeap::MinHeapNode* HuffmanQueue::dequeue()
{
    return heap.extractMin();
}

int HuffmanQueue::size()
{
    return heap.size();
}
