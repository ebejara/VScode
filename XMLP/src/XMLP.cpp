/*//============================================================================
// Name        : XMLP.cpp
// Author      : EB
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================*/

#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>  
#include "..\include\pugixml-1.14\src\pugixml.hpp"
#include "myxml.hpp"
#include "XMLP_Texts.hpp"
using namespace std;

bool exists_test0 (const std::string& name);
int parse_string(std::string str, int &pcount, char *strarray[]);

int main(int argc, char *argv[]) 
{
    Myxmldoc xlang;
    char* filename[256];
    const char* txtstr;
    char cstr[256];
    std::string exitstr = "exit";
    std::string tmptxtstr;
    int remNotID = 0;
    int addNotID = 0;
    char yesnoanswer = 0;
    // int loadResult = -1;
    //std::string filename;
    do{ // while loop
      if (argc == 1){
          std::cout << "Please enter XML-file name (incl. path) " << std::endl;
          PROMT
          std::cin >> *filename; // file name is stored in pointer
          PROMT
            
       
      }
      else{
        //  std::cout<<"Inside else "<< std::endl;
          for(int i = 0; i < argc; i++){
           // std::cout << "argv["<< i<< "]" << argv[i] << std::endl;
            // std::cout << "i = " << i << std::endl;
            if (strcmp(argv[i],"-r") == 0 && argc > i){ //Compare. O means compare is OK
               // std::cout << "Inside -r. argv[i + 1] is: " << argv[i+1]  << std::endl;
                remNotID = atoi(argv[i+1]);
               // std::cout << "remNotID: " << remNotID  << std::endl;
                if (remNotID <= 0){
                    std::cout << REM_ID_WRONG_ID << argv[i] << std::endl;
                    PROMT
                  }
                /*if (loadResult != 0){
                    std::cout << NO_FILE << std::endl;
                    PROMT// defined MACRO
                  }
                else if(loadResult == 0 && notID > 0){
                    std::cout << TRY_REM_ID << notID<< std::endl;
                    PROMT // defined MACRO
                  }*/
                 ++i;
              }
            else if(strcmp(argv[i],"-o") == 0 && argc > i){
                    *filename = (argv[i + 1]);
                   // std::cout << "Filename is: " << *filename <<  endl;
                    if(!exists_test0 (*filename)){
                       std::cout << FILE_NOT_EXIST <<std::endl;
                       PROMT
                    }
                   // std::cout << TRY_FILE << *filename<< std::endl;
                   // loadResult = xlang.load_file(*filename);
                   // PROMT // defined MACRO
                   ++i;
              }
            else if (strcmp(argv[i],"-n") == 0 && argc > i){
                    if (argc > (i + 1)){
                       txtstr = argv[i+1]; // text has quotationsmarks then copy to varible
                       std::cout << "Text string: " << txtstr <<  endl;
                       PROMT
                     }
                    else{
                      std::cout << TEXT_MISSING << argv[i] << std::endl;
                      PROMT}
                    ++i;
              }
            else{
              ;
            }
          } // for
         // std::cout << "Filename: " << *filename <<  endl;
          //std::cout << "remNotID: " << remNotID <<  endl;
        //std::cout << "addNotID: " << addNotID << "Text strig: " << txtstr <<  endl;
      }
      //std::cout << "Load file Error code: " << xlang.load_sts_code(); 
      //std::cout << "  Description: " << xlang.load_sts_descr() << std::endl;
      //std::cout << std::endl;
      //std::cout << "Last notification is: " << xlang.find_last_notID() << std::endl;
      //std::cout << "Last menu item ID is: " << xlang.find_last_menuitemID() << std::endl;
      //std::cout << "Number on Not IDs is : " << xlang.count_of_NotID()<< std::endl;
      //std::cout << "Number on Menu item IDs is : " << xlang.count_of_menuitemID()<< std::endl;
      //std::cout << "ID 152 is: "<< xlang.find_TextbyID(152) << std::endl;
      // std::cout << "Add node code: " << xlang.append_node()<< std::endl;
      //  std::cout << "Adding Notification: " << xlang.append_notification("Hello World")   << std::endl;
      //xlang.printall();
        PROMT
       if (xlang.load_file(*filename) == 0) // file is loaded correctly
       {
          if (txtstr != nullptr ){
            addNotID = xlang.find_last_notID();
            std::cout << NOT_NEW_ID_Q << (++addNotID) << NOT_NEW_TXT << txtstr << endl;
            PROMT
            std::cout << YES_NO << endl;
            PROMT
            yesnoanswer = getchar();
             if (yesnoanswer == 'y'){
                xlang.append_notification(txtstr);}
            txtstr = nullptr; // reset text string
          }
          else{
            std::cout << NOT_NEW_ID_Q << addNotID + 1 << NOT_NEW_TXT << txtstr << endl;
            PROMT
          }


       }
        PROMT
        std::cin.getline(cstr,256);
        PROMT
        std::cout << "debug text after getline:  " << cstr << endl;
        PROMT
        parse_string(cstr, argc, argv);
        std::cout << "argv["<< 0 << "]" << argv[0] << std::endl;
        std::cout << "argv["<< 1 << "]" << argv[1] << std::endl;
        std::cout << "argv["<< 2 << "]" << argv[2] << std::endl;
        std::cout << "argv["<< 3 << "]" << argv[3] << std::endl;
        PROMT
   
    } 
    while(strcmp(cstr,"exit") != 0);
    return 0;
}

inline bool exists_test0 (const std::string& name) {
                    ifstream f(name.c_str());
                      return f.good();
}

int parse_string(std::string str, int &pcount, char *strarray[]){
  std::cout << "Inside parse_string" << endl;
  std::string s;
  int i = 0;
    //char* &argv[];
    //str = "I love to read articles on Favtutor.";

    // ss is an object of stringstream that references the S string.  
    std::stringstream ss(str); 

    // Use while loop to check the getline() function condition.  
    while (getline(ss, s, ' ')) {
        // `str` is used to store the token string while ' ' whitespace is used as the delimiter.
        cout << str << endl;
       // int n = s.length();
        strcpy(strarray[i], s.c_str());
        strarray[i] = s;
         std::cout << "Parse String word: " << strarray[i] << endl;
        ++i;
        pcount = i;
    }

    return 0;
}