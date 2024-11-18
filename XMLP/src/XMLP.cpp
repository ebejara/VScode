/*//============================================================================
// Name        : XMLP.cpp
// Author      : EB
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================*/

#include <iostream>
#include "..\include\pugixml-1.14\src\pugixml.hpp"
#include "myxml.hpp"
//using namespace std;



int main(int argc, char *argv[]) 
{
    Myxmldoc xlang;
    char* filename[100];
  //std::string filename;

    if (argc == 1){
	    std::cout << "Please XML-file name (incl. path) " << std::endl;
        std::cout << "If no file name is given, then default XML file will be loaded." << std::endl;
        std::cout << "XMLP>"; 
        std::cin >> *filename;  
      //  std::cout << "Filename: " << filename << std::endl;
    }
    else{
            std::cout<<"Inside else "<< std::endl;
        for(int i = 0; i <= argc; i++){
            std::cout << "argv["<< i<< "]" << argv[i] << std::endl;
           
            if (argv[i] == "r")
               std::cout << "match"<< std::endl;
              /*  switch (argv[i]){
         
                case "-o":
                    *filename = argv[i];
                    std::cout << *argv[i]<< std::endl;
                break;
                
                case "-h":
                   std::cout << "Helptext" << std::endl;
                break;
                }*/
            
        }
    }
     std::cout << "Filename is  " << filename << std::endl;
     xlang.load_file(*filename);
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
    return 0;
}
