/* *
* Title : Heaps and AVL Trees
* Author : Mian Usman Naeem Kakakhel
* Description : description of your code
*/

#ifndef __HUFFMANCODE_H
#define __HUFFMANCODE_H

#include "HuffmanQueue.h"

class HuffmanCode {


    public:
        
        HuffmanCode();

        HuffmanHeap::MinHeapNode* Huffman(int* freq, char* myChar, int n);


};




#endif
