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
#include "..\include\pugixml-1.14\src\pugixml.hpp"
#include "myxml.hpp"
#include "XMLP_Texts.hpp"
using namespace std;

bool exists_test0 (const std::string& name);

int main(int argc, char *argv[]) 
{
    Myxmldoc xlang;
    char* filename[256];
    const char* txtstr;
    char cstr[256];
    std::string exitstr = "exit";
    int remNotID = 0;
    int addNotID = 0;
    int loadResult = -1;
    //std::string filename;
    
      if (argc == 1){
          std::cout << "Please enter XML-file name (incl. path) " << std::endl;
          PROMT
          std::cin >> *filename;
          PROMT
            
        //  std::cout << "Filename: " << filename << std::endl;
      }
      else{
          std::cout<<"Inside else "<< std::endl;
          for(int i = 1; i <= argc; ++i){
            std::cout << "argv["<< i<< "]" << argv[i] << std::endl;
             std::cout << "i = " << i << std::endl;
            if (strcmp(argv[i],"-r") == 0 && argc > i){ //Compare. O means compare is OK
                std::cout << "Inside -r. argv[i + 1] is: " << argv[i+1]  << std::endl;
                remNotID = atoi(argv[i+1]);
                std::cout << "remNotID: " << remNotID  << std::endl;
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
                    std::cout << "Filename is: " << *filename <<  endl;
                    if(!exists_test0 (*filename)){
                       std::cout << FILE_NOT_EXIST <<std::endl;
                       PROMT
                    }
                   // std::cout << TRY_FILE << *filename<< std::endl;
                   // loadResult = xlang.load_file(*filename);
                   // PROMT // defined MACRO
                   ++i;
              }
            else if (strcmp(argv[i],"-a") == 0 && argc > i){
                    addNotID = atoi(argv[i+1]);
                    std::cout << "addNotID: " << addNotID  << std::endl;
                    
                    if (argc > (i + 1) && addNotID > 0)
                       txtstr = argv[i+1];
                       std::cout << "addNotID: " << addNotID << "Text strig: " << txtstr <<  endl;
                    else if (addNotID <= 0 && argc > (i+1) )
                      std::cout << REM_ID_WRONG_ID << argv[i] << std::endl;
                    else if (addNotID > 0 && argc <= (i+1))
                      std::cout << TEXT_MISSING << argv[i] << std::endl;
                    else{
                      std::cout << REM_ID_WRONG_ID << argv[i] << std::endl;
                      std::cout << TEXT_MISSING << argv[i] << std::endl;
                      PROMT
                    }
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
      
   do{ // while loop

      std::cin.getline(cstr,256);
      PROMT
      std::cout << "debug text after getline" << cstr << endl;
      PROMT
   
    } 
    while(strcmp(cstr,"exit") != 0);
    return 0;
}

inline bool exists_test0 (const std::string& name) {
                    ifstream f(name.c_str());
                      return f.good();
}