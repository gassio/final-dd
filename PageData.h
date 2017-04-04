#ifndef pageData
    #define pageData
    #include <iostream>
    #include "AVLTree.h"
    
    using namespace std;
    
    class PageData
    {
          private:
          		  int id;
                  AVLTree *pageAVL;
                  int size;
          public:
                PageData();
                PageData(int id);
                PageData(int id, int size, AVLTree *pageAVL);
                ~ PageData();
                int getId();
                int getSize();
                bool insertPage (int x);
                bool deletePage (int x);
                void writeToFile(ofstream *outfile);
    };
#endif
