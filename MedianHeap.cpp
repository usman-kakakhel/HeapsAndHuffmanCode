/* *
* Title : Heaps and AVL Trees
* Author : Mian Usman Naeem Kakakhel
* Description : description of your code
*/

#include "MedianHeap.h"

MedianHeap::MedianHeap()
{

}


void MedianHeap::insert ( int value )
{
    int median = findMedian();//find the value of the median
    if (min_Heap.size() > max_Heap.size())//if min heap is greater in size
    {
        if (value > median)//if value is greater than median then we have to enter in min heap but then we will have a difference of more than 1 
        {                  //in the heaps sizes thus we shift the smallest value in the minheap to max heap and add the new value to min heap
            max_Heap.insert(min_Heap.extractMin());
            min_Heap.insert(value);
        }
        else
            max_Heap.insert(value); 
    }
    else if (min_Heap.size() < max_Heap.size())//if max heap is greater in size
    {
        if (value < median)//if value is smaller than median then we have to enter in max heap but then we will have a difference of more than 1 
        {                  //in the heaps sizes thus we shift the largest value in the maxheap to min heap and add the new value to max heap
            min_Heap.insert(max_Heap.extractMax());
            max_Heap.insert(value);
        }
        else
            min_Heap.insert(value);
    }
    else//if both are same in size
    {
        if (median > value)//sizes are same so enter in max heap if value is smaller than median
            max_Heap.insert(value);
        else
            min_Heap.insert(value);
    }
    
}


int MedianHeap::findMedian ()
{
    int median;
    if (min_Heap.size() > max_Heap.size())//if min heap is greater than max heap then the median exists only in the min heap
        median = min_Heap.peek();
    else if (min_Heap.size() < max_Heap.size())//if max heap is greater than min heap then the median exists only in the max heap
        median = max_Heap.peek();
    else
    {
        if (min_Heap.size() == 0)//if both heaps are empty then return 0
            return 0;
        median = min_Heap.peek();//if both sizes are equal then median is the one in min heap as min heap contains the greater values than max heap
    }   
    return median;
}
