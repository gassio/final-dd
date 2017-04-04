#ifndef myAVLTree
    #define myAVLTree
    #include <iostream>
    
    using namespace std;
    
    class AVLTree
    {
          private:
                 class node
                  {
                        public:
                            int number;
                            node *LeftChild, *RightChild; 
                  };
                  node *list_head;
                  int size;
                  void PrivateInOrder (node *p, int *result, int i); 
                  void PrivatePreOrder (node *p, int *result, int i);
                  void PrivatePostOrder (node *p, int *result, int i);
          public:
                AVLTree();
                ~AVLTree();
                int Insert (int x);
                int Delete (int x);
                bool Search (int x);
                int GetSize();
                void InOrder (int *result);
                void PreOrder (int *result);
                void PostOrder (int *result);
    };
#endif
