#ifndef arrayPages
    #define arrayPages
    
    #include <iostream>
    #include <fstream>
    #include <cmath>
    #include "PageData.h"
    
    using namespace std;
    
    class ClassInvertedIndex {
          private:
                 class node
                  {
                        public:
                            PageData *kombos;
                            node *LeftChild, *RightChild; 
                  };
                  node *list_head;
                  int size;
                  void PrivateInOrder (node *p, int *result, int i); 
                  void PrivatePreOrder (node *p, int *result, int i);
                  void PrivatePostOrder (node *p, int *result, int i);
          public:
                ClassInvertedIndex();
                ~ClassInvertedIndex();
                void insertPage(int id, int x);
                void deletePage(int id, int x);
                void writeFile(char fileName[30]);
                void readFile(char fileName[30]);
                int Insert (int x);
                int Delete (int x);
                PageData *Search (int x);
                int GetSize();
                void InOrder (int *result);
                void PreOrder (int *result);
                void PostOrder (int *result);
    };
#endif
