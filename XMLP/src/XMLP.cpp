/*//============================================================================
// Name        : XMLP.cpp
// Author      : EB
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================*/

#include <iostream>
#include <string>
#include "..\include\pugixml-1.14\src\pugixml.hpp"
#include "myxml.hpp"
#include "XMLP_Texts.hpp"
using namespace std;



int main(int argc, char *argv[]) 
{
    Myxmldoc xlang;
    char* filename[256];
    char cstr[256];
    std::string exitstr = "exit";
    int notID = 0;
    int loadResult = -1;
    //std::string filename;
    
      if (argc == 1){
          std::cout << "Please enter XML-file name (incl. path) " << std::endl;
          std::cout << "XMLP>"; 
          std::cin >> *filename;  
        //  std::cout << "Filename: " << filename << std::endl;
      }
      else{
          std::cout<<"Inside else "<< std::endl;
          for(int i = 1; i <= argc; ++i){
            //std::cout << "argv["<< i<< "]" << argv[i] << std::endl;
            // std::cout << "i = " << i << std::endl;
            if (!strcmp(argv[i],"-r")){ //Compare. O means compare is OK
                notID = atoi(argv[i+1]);
                if (loadResult != 0){
                    std::cout << NO_FILE << std::endl;
                    PROMT// defined MACRO
                  }
                else if(loadResult == 0 && notID > 0){
                    std::cout << TRY_REM_ID << notID<< std::endl;
                    PROMT // defined MACRO
                  }
              }
            else if(!strcmp(argv[i],"-o")){
                    *filename = (argv[i + 1]);
                    std::cout << TRY_FILE << *filename<< std::endl;
                    loadResult = xlang.load_file(*filename);
                    PROMT // defined MACRO
              }
              else if (!strcmp(argv[i],"-i")){

              }
          }
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
      std::cout << "debug text after getline" << cstr << endl;
   
    } 
    while(1);
    return 0;
}