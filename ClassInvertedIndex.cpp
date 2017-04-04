#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include "stdio.h"

using namespace std;
#include "PageData.h"
#include "ClassInvertedIndex.h"


    ClassInvertedIndex::ClassInvertedIndex(){ 
        list_head = NULL;      
      	this->size=0;  
    }
    ClassInvertedIndex::~ClassInvertedIndex() { 
		delete list_head;
      
      	this->size=0;
	}
	
    PageData *ClassInvertedIndex::Search (int x) {
	     node *p = list_head;
	     
	     while (p) {
	           if (x < p->kombos->getId()) p = p->LeftChild;
	           else if (x > p->kombos->getId()) p = p->RightChild;
	                else {return p->kombos;}
	     }
	     return NULL;
	}
	
    void ClassInvertedIndex::insertPage(int id, int x){
    	PageData *k = this->Search(id);
    	
		if (k != NULL) {
			k->insertPage(x);
        }
        else {
			this->Insert(id);
			k = this->Search(id);
			k->insertPage(x);
		}
    }
    
    void ClassInvertedIndex::deletePage(int id,int x){
        if (this->Search(id) != NULL) {
			if (!this->Search(id)->deletePage(x)) this->Delete(id);
		}
    }
    
    void ClassInvertedIndex::writeFile(char fileName[30]){
         int k;
         ofstream outfile;
         
         outfile.open(fileName, ios::out);
         int pin[100000], i;
         //cout << pre
	     this->PreOrder(pin);
	      
	      for (i=0; i <= this->GetSize()-1; i++) {
	          if (this->Search(pin[i]) != NULL) this->Search(pin[i])->writeToFile(&outfile);
	      }
         
         outfile.close();
    }
    
    void ClassInvertedIndex::readFile(char fileName[30]) {
         
        int id, x, k, i;
        ifstream infile;
        char buffer[30], chnum1[10],chnum2[10];
        
        infile.open(fileName, ios::in);
        
        while(infile.getline(buffer,30))
        {
            i = 0;
            k = 0;
            while (buffer[i]!='\t') {               
                chnum1[k]=buffer[i];
                i++;
                k++;
            }
            chnum1[k]='\0';
            id=atoi(chnum1);
    
            k = 0;
            i++;
            while (buffer[i]!='\0') {               
                chnum2[k]=buffer[i];
                i++;
                k++; 
            }
            chnum2[k]='\0';
            x=atoi(chnum2);
            
            this->insertPage(id, x);
        }
        
        infile.close();
     }
int ClassInvertedIndex::Insert (int x)
{
     node *p1 = new node;
     PageData *k = new PageData(x);
     if (list_head == NULL) {p1->kombos = k; p1->LeftChild = NULL; p1->RightChild = NULL; list_head = p1;}
     else {
         node *p = list_head, *pp = NULL;
         while(p) {
             pp=p;
             if (x < p->kombos->getId()) p = p->LeftChild;
             else if (x > p->kombos->getId()) p = p->RightChild;
                  else return -1;
         }
          if(list_head) {
             if (x < pp->kombos->getId()) {pp->LeftChild = p1; p1->kombos = k, 
                                 p1->LeftChild = NULL, p1->RightChild= NULL;
             }
             else { pp->RightChild = p1; p1->kombos = k, 
                                 p1->LeftChild = NULL, p1->RightChild= NULL;
             }
             pp = p1;
         }
         else { list_head->kombos = k, list_head->LeftChild = NULL, list_head->RightChild= NULL; }
     }
     this->size++;
     return 1;
}

int ClassInvertedIndex::Delete (int x)
{
     node *p = list_head, *pp = NULL;
     while(p && p->kombos->getId() != x) {
         pp=p;
         if (x < p->kombos->getId()) p = p->LeftChild;
         else if (x > p->kombos->getId()) p = p->RightChild;
              else return -1;
     }
     if (!p) return -1;
     int e = p->kombos->getId();
     if (p->LeftChild && p->RightChild) {
         node *s = p->LeftChild, *ps = p;
         while (s->RightChild) { ps = s, s = s->RightChild; }
         p->kombos = s->kombos;
         p = s;
         pp = ps;
     }
     node *c;
     if (p->LeftChild) c = p->LeftChild;
     else c = p->RightChild;
     
     if (p == list_head) list_head = c;
     else { if (p == pp->LeftChild) pp->RightChild = c;
            else pp->RightChild = c;}
     delete p;
     this->size--;
     return 1;
}



int ClassInvertedIndex::GetSize()
{
    return this->size;
}

void ClassInvertedIndex::PrivatePreOrder(node *t, int *result, int i) {
     if (t) {
         result[i] = t->kombos->getId();  
         PrivatePreOrder(t->LeftChild, result, i+1);
         PrivatePreOrder(t->RightChild, result, i+1);
     }
}
void ClassInvertedIndex::PreOrder(int *result)
{
     node *p = list_head;
     this->PrivatePreOrder(p, result, 0);
}

void ClassInvertedIndex::PrivateInOrder(node *t, int *result, int i)
{
     if (t) {
         PrivateInOrder(t->LeftChild, result, i+1);
         result[i] = t->kombos->getId();
         PrivateInOrder(t->RightChild, result, i+1);
     }
}
void ClassInvertedIndex::InOrder(int *result)
{
     node *p = list_head;
     this->PrivateInOrder(p, result, 0);
}

void ClassInvertedIndex::PrivatePostOrder(node *t, int *result, int i)
{
     if (t) {
         PrivatePreOrder(t->LeftChild, result, i+1);
         PrivatePreOrder(t->RightChild, result, i+1);
         result[i] = t->kombos->getId();
     }
}
void ClassInvertedIndex::PostOrder(int *result)
{
     node *p = list_head;
     this->PrivatePostOrder(p, result, 0);
}
