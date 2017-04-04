#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;
#include "AVLTree.h"

AVLTree::AVLTree()
{
      list_head = NULL;           
      this->size=0;             
}

AVLTree::~AVLTree()
{
      delete list_head;
      
      this->size=0;               
}
    
int AVLTree::Insert (int x)
{
     
     node *p1 = new node;
     
     if (list_head == NULL) {p1->number = x; p1->LeftChild = NULL; p1->RightChild = NULL; list_head = p1;}
     else {
         node *p = list_head, *pp = NULL;
         while(p) {
             pp=p;
             if (x < p->number) p = p->LeftChild;
             else if (x > p->number) p = p->RightChild;
                  else return -1;
         }
          if(list_head) {
             if (x < pp->number) {pp->LeftChild = p1; p1->number = x, 
                                 p1->LeftChild = NULL, p1->RightChild= NULL;
             }
             else { pp->RightChild = p1; p1->number = x, 
                                 p1->LeftChild = NULL, p1->RightChild= NULL;
             }
             pp = p1;
         }
         else { list_head->number = x, list_head->LeftChild = NULL, list_head->RightChild= NULL; }
     }
     this->size++;
     return 1;
}

int AVLTree::Delete (int x)
{
     node *p = list_head, *pp = NULL;
     while(p && p->number != x) {
         pp=p;
         if (x < p->number) p = p->LeftChild;
         else if (x > p->number) p = p->RightChild;
              else return -1;
     }
     if (!p) return -1;
     int e = p->number;
     if (p->LeftChild && p->RightChild) {
         node *s = p->LeftChild, *ps = p;
         while (s->RightChild) { ps = s, s = s->RightChild; }
         p->number = s->number;
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

bool AVLTree::Search (int x) {
     node *p = list_head;
     
     while (p) {
           if (x < p->number) p = p->LeftChild;
           else if (x > p->number) p = p->RightChild;
                else {return true;}
     }
     return false;
}

int AVLTree::GetSize()
{
    return this->size;
}

void AVLTree::PrivatePreOrder(node *t, int *result, int i) {
     if (t) {
         result[i] = t->number;  
         PrivatePreOrder(t->LeftChild, result, i+1);
         PrivatePreOrder(t->RightChild, result, i+1);
     }
}
void AVLTree::PreOrder(int *result)
{
     node *p = list_head;
     this->PrivatePreOrder(p, result, 0);
}

void AVLTree::PrivateInOrder(node *t, int *result, int i)
{
     if (t) {
         PrivateInOrder(t->LeftChild, result, i+1);
         result[i] = t->number;
         PrivateInOrder(t->RightChild, result, i+1);
     }
}
void AVLTree::InOrder(int *result)
{
     node *p = list_head;
     this->PrivateInOrder(p, result, 0);
}

void AVLTree::PrivatePostOrder(node *t, int *result, int i)
{
     if (t) {
         PrivatePreOrder(t->LeftChild, result, i+1);
         PrivatePreOrder(t->RightChild, result, i+1);
         result[i] = t->number;
     }
}
void AVLTree::PostOrder(int *result)
{
     node *p = list_head;
     this->PrivatePostOrder(p, result, 0);
}


