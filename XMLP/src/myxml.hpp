//#pragma once
#include <iostream>
#include <string>
#include <variant>
#include "..\include\pugixml-1.14\src\pugixml.hpp"


class Myxmldoc
{
  
  public:
  /*Constructors for Class Myxmldoc*/
  //  Myxmldoc ();
  // Myxmldoc (const char *path);
  
  /*Variables and constants for CLass Myxmldoc*/
  //std::string first_menu_text = "1500"; //First Non-Ntification ID
  int first_menu_text = 1500;
  pugi::xml_document doc;
  pugi::xml_document tempDoc;
  pugi::xml_node rootnodeTmp;

  
  /*Load the default XML-file*/
  pugi::xml_parse_result result = doc.load_file("../file/Language_file_20240406.xml");
  /*Load the relevant child from the XML-file*/
  pugi::xml_node mastertxts = doc.child("TextExchangeFormat").child("MasterMessages").child("MasterMessageAdvanced");     
     
 int load_file(char *filename){
    pugi::xml_parse_result result = doc.load_file(filename);
    std::cout << "Error code: " << load_sts_code(result) << std::endl;
    std::cout << "Error description: " << load_sts_descr(result) << std::endl;
    if (load_sts_code(result) == 0){
      std::cout << "XML file loaded"<< std::endl;
    }

      std::cout << "Debug text: "<< filename <<std::endl;
    return 0;
 }  
      
 /* Returns the error code of the XML-loading process*/
  int load_sts_code(pugi::xml_parse_result result)
  {
    return result.status; 
  };

 /* Returns the error code description of the XML-loading process*/
  const char* load_sts_descr(pugi::xml_parse_result result)
  {
    
    return result.description();
  };
       
 /*Finds the last notification ID from the XML-file*/
  int find_last_notID() const
  {
    pugi::xml_node mastertxt = mastertxts;
  
    for(mastertxt.first_child(); mastertxt; mastertxt = mastertxt.next_sibling("MasterMessageAdvanced"))
    {
      if (mastertxt.first_child().text().as_int() == first_menu_text)
      {
        //std::cout << "In-If: " << mastertxt.first_child().text().as_int() << std::endl;
        return mastertxt.previous_sibling().first_child().text().as_int();
      }
    }
    return 0;
  };

  /*Counts the number of menu item Ids.*/
  int count_of_NotID() const
  {
    int ncount = 0;
    pugi::xml_node mastertxt = mastertxts;
    for(mastertxt.first_child(); mastertxt; mastertxt = mastertxt.next_sibling("MasterMessageAdvanced"))
    {
      if (mastertxt.first_child().text().as_int() < first_menu_text)
      {
        ++ncount;
      }
      else
      {
        return ncount;
      }
    }
    return -1; // return error.
  };

  /*Counts the number of menu item Ids.*/
  int count_of_menuitemID() const
  {
    int mcount = 0;
    pugi::xml_node mastertxt = mastertxts;
    for(mastertxt.first_child(); mastertxt; mastertxt = mastertxt.next_sibling("MasterMessageAdvanced"))
    {
      if (mastertxt.first_child().text().as_int() >= first_menu_text)
      {
        ++mcount;
      }
    }
    return mcount;
  }

   /*Finds the last menu item ID*/
  int find_last_menuitemID()
  {
    pugi::xml_node mastertxt = mastertxts;
    /*go to last mastertextsibling and then to its child "MSGID"*/
    return mastertxt.parent().last_child().first_child().text().as_int();
  }

  /*Finds the corresponding master text to the specified ID*/
  const char* find_TextbyID(int ID)
  {
      pugi::xml_node mastertxt = mastertxts;
    
      for(mastertxt.first_child(); mastertxt; mastertxt = mastertxt.next_sibling("MasterMessageAdvanced"))
      {
        if (mastertxt.first_child().text().as_int()== ID)
        {
        return mastertxt.last_child().text().as_string();
        }
      }
    return "ID not found"; // Id was not found.

  };

 /* Checks if ID already exists*/
  bool ID_exists(int ID)
  {
      pugi::xml_node mastertxt = mastertxts;
      for(mastertxt.first_child(); mastertxt; mastertxt = mastertxt.next_sibling("MasterMessageAdvanced"))
      {
        if (mastertxt.first_child().text().as_int()== ID){
           return true; // ID exixts in loaded XMl file
        }
      }
      return false;
  }

 
  int append_notification(const char* txt)
  {
    int last_ID = find_last_notID(); // find the last ID for Notifications.
    char idstr[4];
    itoa(last_ID+1,idstr,10); // The Notification ID in text format 
    pugi::xml_node MasterMessages = mastertxts.parent();// "MasterMessages"
    pugi::xml_node MastertextAdvanced = mastertxts.parent().first_child();//Set to first item of "MastertextAdvanced"
    rootnodeTmp = doc.child("TextExchangeFormat");
    tempDoc.append_copy(rootnodeTmp);
    tempDoc.save_file("../file/tempdoc.xml");
    std::cout << "tempDoc is now copy of original XML-file"<< std::endl<<std::endl;//Printing NewNot
    //tempDoc.print(std::cout,"",pugi::format_indent);
    std::cout << "string ID is :" << idstr << std::endl;//Printing out master text
    MasterMessages.remove_children(); //Clear node. To be filled up again in for-loop
    std::cout << "LastID before for is :" << idstr << std::endl;//Printing out master text
    // std::cout << "Number of Not IDs:" << count_of_NotID() << std::endl;//Printing out master text
    std::cout << std::endl << std::endl << std::endl;
    // std::cout << "Print out all MastertextAdvanced texts "<< std::endl<<std::endl;//Printing MastertextAdvanced
        
        for(MastertextAdvanced = mastertxts; MastertextAdvanced; MastertextAdvanced = MastertextAdvanced.next_sibling("MasterMessageAdvanced"))
        {
         // std::cout << "Current MSG ID: " << MastertextAdvanced.first_child().text().as_int() << std::endl;
          //std::cout << "Next MSG ID:" << MastertextAdvanced.next_sibling().first_child().text().as_int() << std::endl;
           MasterMessages.append_copy(MastertextAdvanced);
          // MastertextAdvanced.print(std::cout,"",pugi::format_indent);
         if (MastertextAdvanced.first_child().text().as_int() == last_ID)
          {
            std::cout << "Inside if" << std::endl;
            MasterMessages.append_copy(MastertextAdvanced);
            MasterMessages.last_child().first_child().first_child().set_value(idstr);
            MasterMessages.last_child().last_child().first_child().set_value(txt);
          }
            MastertextAdvanced = MastertextAdvanced.next_sibling("MasterMessageAdvanced");
          
        }
       
           
      std::cout << "printing Mastermessages"<< std::endl<< std::endl<< std::endl;
      MasterMessages.print(std::cout,"",pugi::format_indent);
      return 0;          
  }

  void save_file()
  {
    doc.save_file("../file/Language_file_20240406.xml");
    
  
  }

  void printall(){
    doc.print(std::cout,"",pugi::format_indent);
  }

};