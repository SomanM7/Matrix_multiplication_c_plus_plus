#include <iostream>
#include <vector>
#include "Matrix.h"
#include <fstream>
#include <iterator>
#include <time.h>
#include <cmath>
#include <stdio.h>
#include <string.h>



using namespace std;

int main(int argc, char* argv[]){
    Matrix ma_object;
    Matrix *ma_pointer = new Matrix();
    if( argc != 5 )
    {
        printf("invalid number of arguments.\n");
    }
    else{


        if(strcmp(argv[2] , "x" ) == 0){
            char *Eptr;
            long val3 = strtol(argv[3], &Eptr,10);
            if (*Eptr == '\0'){
                ma_object.fill_from_file(argv[1]);
                ma_object.mult(atoi(argv[3]));
                ma_object.print();
                char* val4 = argv[4];
                ma_object.store_in_file(val4);
            
            }
            else{
                ma_object.fill_from_file(argv[1]);
                ma_object.mult(ma_pointer,argv[3]);
                ma_object.print();
                char* val4 = argv[4];
                ma_object.store_in_file(val4);
                
            }
        }
        else{
                cout << "incorrect operation222222";
                return EXIT_FAILURE;
            }

            if(strcmp(argv[2] , "+" ) == 0){
            char *Eptr;
            long val3 = strtol(argv[3],&Eptr,10);
            if (*Eptr == '\0'){
                ma_object.fill_from_file(argv[1]);
                ma_object.add(atoi(argv[3]));
                ma_object.print();
                char* val4 = argv[4];
                ma_object.store_in_file(val4);
            
            }
            else{
                ma_object.fill_from_file(argv[1]);
                ma_object.add(ma_pointer,argv[3]);
                ma_object.print();
                char* val4 = argv[4];
                ma_object.store_in_file(val4);
                
            }
        }
        else{
                cout << "incorrect operation33333333";
                return EXIT_FAILURE;
            }
        }
            return 0;
    }
