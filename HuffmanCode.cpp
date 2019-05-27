/* *
* Title : Heaps and AVL Trees
* Author : Mian Usman Naeem Kakakhel
* Description : description of your code
*/

#include "HuffmanCode.h"


HuffmanCode::HuffmanCode()
{}


HuffmanHeap::MinHeapNode* HuffmanCode::Huffman(int* freq, char* myChar, int n)
{
    HuffmanQueue q;
    for (int i = 0; i < n; i++)
    {
        HuffmanHeap::MinHeapNode* a = new HuffmanHeap::MinHeapNode();//make a node for every char
        a->freq = freq[i];
        a->character = myChar[i];
        a->left = NULL;
        a->right = NULL;
        q.enqueue(a);//put it in the queue
    }

    for (int i = 0; i < n - 1; i++)
    {
        HuffmanHeap::MinHeapNode* z = new HuffmanHeap::MinHeapNode();//make a new node
        z->left = q.dequeue();//dequeue a node
        z->right = q.dequeue();//dequeuue a nnode
        z->freq = (z->left)->freq + (z->right)->freq;//add the 2 freq
        q.enqueue(z);//enqueue the new node
    }

    return q.dequeue();//return node rooted at hte tree
}
