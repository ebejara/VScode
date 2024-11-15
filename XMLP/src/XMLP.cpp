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



int main() 
{
	std::cout << "XML file will be loaded!" << std::endl;   
    Myxmldoc xlang;
	//std::cout << "Load file Error code: " << xlang.load_sts_code(); 
    //std::cout << "  Description: " << xlang.load_sts_descr() << std::endl;
    //std::cout << std::endl;
	//std::cout << "Last notification is: " << xlang.find_last_notID() << std::endl;
    //std::cout << "Last menu item ID is: " << xlang.find_last_menuitemID() << std::endl;
    //std::cout << "Number on Not IDs is : " << xlang.count_of_NotID()<< std::endl;
    //std::cout << "Number on Menu item IDs is : " << xlang.count_of_menuitemID()<< std::endl;
    //std::cout << "ID 152 is: "<< xlang.find_TextbyID(152) << std::endl;
   // std::cout << "Add node code: " << xlang.append_node()<< std::endl;
      std::cout << "Adding Notification: " << xlang.append_notification("Hello World")   << std::endl;
    //xlang.printall();
    return 0;
}
