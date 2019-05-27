/* *
* Title : Heaps and AVL Trees
* Author : Mian Usman Naeem Kakakhel
* Description : The Output file is written with the characters and their Coding schemes.
*/

#include "HuffmanCode.h"

void getCodingSchemes( HuffmanHeap::MinHeapNode* root, int &cntr, string &schP, fstream& myfile)
{
        if (root != NULL)
        {
                if ((root->left == NULL) && (root->right == NULL))//if we are at a leaf node
                {
                myfile << root->character << " " << schP.substr(0, cntr) << endl;//wrte the data in the file
                }

                schP = schP.substr(0,cntr) + "0";//if going left, append 0 to the string
                cntr++;
                getCodingSchemes( root->left, cntr, schP, myfile);//left recursive call

                schP = schP.substr(0,cntr) + "1";//if going right, append 1 to the string
                cntr++;
                getCodingSchemes( root->right, cntr, schP, myfile);//right recursive call
        }
        cntr--;
}

int main(int argc, char *argv[])
{
        fstream myfile;
        
        if (argc == 3)
        {
                string fileName, fileName1;
                fileName = argv[1];
                fileName1 = argv[2];
                int len;
                //cout << "enter name of input file: " << endl;
                //cin >> fileName;//get the name of the input file
                //fileName = fileName + ".txt";//append .txt to it
                len = fileName.length();//get the length of the string
                char cArr[len + 1];//make a char array of the size
                strcpy(cArr, fileName.c_str());//copy the string characters into the char array

                
                myfile.open(cArr, ios::in);//open the input file

                int freq[128];
                char chars[128];
                int size = 0;

                while (myfile >> chars[size] >> freq[size])//get freq and characters from file
                {
                        size++;
                }
                        
                myfile.close();

                HuffmanCode hCode;
                HuffmanHeap::MinHeapNode* root = hCode.Huffman(freq, chars, size);//get the node rooted at the tree

                

                int cntr = 0;
                string schP;


                //cout << "enter name of output file: " << endl;
                //cin >> fileName;//get the name of the output file
                //fileName = fileName + ".txt";//append .txt to it
                len = fileName1.length();//get the length of the string
                char cArr1[len + 1];//make a char array of the size
                strcpy(cArr1, fileName1.c_str());//copy the string characters into the char array

                myfile.open(cArr1, ios::out);
                myfile.close();
                myfile.open(cArr1, ios::app);
                getCodingSchemes( root, cntr, schP, myfile);//write the coding schemes in the file
                myfile.close();
        }
        else
        {
                cout << "Arguments do not include 2 files." << endl;
        }
        
        

        return 0;
}

