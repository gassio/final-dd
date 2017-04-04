#include <cstdlib>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cmath>

using namespace std;
#include "PageData.h"
#include "AVLTree.h"

PageData::PageData()
{
      this->id = -1;
      this->size = -1;
      this->pageAVL = NULL;
}

PageData::PageData(int id, int size, AVLTree *pageAVL)
{
      this->id = id;
      this->size = size;
      this->pageAVL = pageAVL;
}
PageData::PageData(int id)
{\
      this->id = id;
      this->pageAVL = new AVLTree();
      this->size = pageAVL->GetSize();
}

PageData::~PageData()
{
      this->id = -1;
      this->size = -1;
      this->pageAVL->~AVLTree();             
}
    
int PageData::getId() {
     return this->id;    
}
    
bool PageData::insertPage (int x)
{
     if (!this->pageAVL->Search(x)) {
        this->pageAVL->Insert(x);
        return true;
     }
     return false;
}

bool PageData::deletePage (int x)
{
    if (this->pageAVL->Search(x)) {
       this->pageAVL->Delete(x);
       return true;
     }
     return false;
}

int PageData::getSize()
{
    this->size = this->pageAVL->GetSize();
    return this->size;
}

void PageData::writeToFile(ofstream *outfile) {
     
     *outfile << this->id << ", ";
     *outfile << this->getSize()<< ", ";
     int h[10000], i;
     this->pageAVL->PreOrder(h);
      
      for (i=0; i <= this->pageAVL->GetSize()-1; i++) {
          *outfile << h[i] ;
          if (i != this->pageAVL->GetSize() - 1) *outfile << ", ";
      }
      *outfile << endl;
}
