#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <stdexcept>
#include <exception>
#include <bits/stdc++.h>  


using namespace std;

int parse_gln(std::string str, int *pargc, char **pargv);

int main(int argc, char *argv[]){

        string istr;
        char **pargv;
        int *pargc;
        char input[256];
        int newargc = 0;
       // Define new pointer to string array
        char **newargv = nullptr;
        int SIZE_ARRAY = 16;
        newargv = (char**)malloc(SIZE_ARRAY *sizeof(char*));
        
        pargv = argv;
        pargc = &argc;

do{
        for (int i = 0; i < argc; ++i){
            cout<< "argv["<<i<<"] " << argv[i]<< endl;

        }

        for (int i = 0; i < *pargc; ++i){
            cout<< "pargv("<<i<<") " << *(pargv + i)<< endl;

        }
        pargv = newargv;
        pargc = &newargc;

        // Allocate memory for each string in teh tsring array.
        for (int i = 0; i < SIZE_ARRAY; i++) {
                newargv[i] = (char*)malloc((255 + 1)* sizeof(char));
                if (newargv[i] == NULL) {
                    cout << "Memory allocation failed"<< endl;
                return 1;
                }
              // cout << "newargv["<<i<<"]" << newargv[i] << endl;
        } // for allocate size of each string

        cout << "Make input >";
        cin.getline(input,256);
        istr = input;
        // std::getline(std::cin, istr);
        cout << "input was: " << istr << endl;
        *pargc = 10;
        parse_gln(istr, pargc, pargv);
}          
 while(strcmp(input, "Exit") != 0); //Do-While 
        
         for (int i = 0; i < SIZE_ARRAY; i++) {
                free(pargv[i]);
          }
        
        cout << "program finished" << endl;
        return 0;

}



int parse_gln(std::string str, int *pargc, char **pargv){
       
        *pargc = 0;
      //  str = "one two three four five six seven";
        std::string s; 
        int i = 0;
            std::stringstream ss(str); 

            // Use while loop to check the getline() function condition.  
            while (getline(ss, s, ' ')) {
                // `str` is used to store the token string while ' ' whitespace is used as the delimiter.
                std::cout << "i =  " << i << endl;
                cout << s << endl;
              
              try{
               strcpy (*(pargv + i), s.c_str());
               //throw("Failed");
              }
              catch(std::exception& e){
                std::cout << "Some exception cought: " << e.what() << endl;

              }
               std::cout << "Parse pargv: " << *(pargv+i) << endl;
                ++i;
                *pargc = i;
            }
            return 0;
} //int parse_gln