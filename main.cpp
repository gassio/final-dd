#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <time.h> 

using namespace std;
#include "AVLTree.h"
#include "PageData.h"
#include "ClassInvertedIndex.h"

int main(int argc, char *argv[])
{
    ClassInvertedIndex *links = new ClassInvertedIndex();

    ifstream infile;

    int i=0,k=0,number1=-1,number2=-1;
    char function[10],chnum1[10],chnum2[10],fileName[10],myBuffer[30];

	infile.open("commands.txt", ios::in);

    while(infile.getline(myBuffer,30))
	{
        i = 0,k=0,number1=-1,number2=-1;

        while (myBuffer[i]!=' ') {
            function[k]=myBuffer[i];
            i++;
            k++;
        }
        function[k]='\0';

        if(strcmp(function,"WRITE_INDEX")==0 || (strcmp(function,"READ_DATA")==0)) {
            k = 0;
            i++;
            while (myBuffer[i]!='\0') {
                fileName[k]=myBuffer[i];
                i++;
                k++;
            }
            fileName[k]='\0';

        }
        else {
            k = 0;
            i++;
            while (myBuffer[i]!=' ') {
                chnum1[k]=myBuffer[i];
                i++;
                k++;
            }
            chnum1[k]='\0';
            number1=atoi(chnum1);

            k = 0;
            i++;
            while (myBuffer[i]!='\0') {
                chnum2[k]=myBuffer[i];
                i++;
                k++;
            }
            chnum2[k]='\0';
            number2=atoi(chnum2);
        }

		 if (strcmp(function,"READ_DATA")==0) {
            links->readFile(fileName);
         }
         else if(strcmp(function,"INSERT_LINK")==0) {
              links->insertPage(number1, number2);
         }
         else if(strcmp(function,"DELETE_LINK")==0) {
              links->deletePage(number1, number2);
         }
         else if(strcmp(function,"WRITE_INDEX")==0) {
              links->writeFile(fileName);
         }

	}

	infile.close();


	system("PAUSE");
    return EXIT_SUCCESS;
}

