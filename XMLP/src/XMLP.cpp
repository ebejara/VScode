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
int parse_string(std::string str, int *pcount, char **pargv);


int main(int argc, char *argv[]) 
{
    Myxmldoc xlang;
    //char filenamebuffer[256];
    char *filename = new char[256]; // Used for XML file reference
    const char* txtstr;
    char cstr[256];
    bool fileLoaded = false;
   // std::string cstr;
    std::string exitstr = "Exit";
    std::string tmptxtstr;
    int remID = 0;
    int addNotID = 0;
    char yesnoanswer = 0;
  
// Define new pointer and buffer for comamnds.
    string istr;
    int *pargc = &argc;
    char **pargv = argv;
    //char input[256];
    int newargc = 0;
    // Define new pointer to string array
    char **newargv = nullptr;
    int SIZE_ARRAY = 16; // maximun 16 commands
    newargv = (char**)malloc(SIZE_ARRAY *sizeof(char*));     //Allocate memory

    // int loadResult = -1;
    //std::string filename;
    
    do{ // while loop
        if (*pargc == 1){
            std::cout << NO_FILE << std::endl;
            PROMT
            //std::cin >> *filename; // file name is stored in pointer
        }
        else{
          //  std::cout<<"Inside else "<< std::endl;
            for(int i = 0; i < *pargc; ++i){
            std::cout << "Inside main *pargv["<< i<< "]" << pargv[i] << std::endl;
              // std::cout << "i = " << i << std::endl;
              if (strcmp(pargv[i],"-r") == 0 && *pargc > i){ //Compare. O means compare is OK
                 std::cout << "Inside -r. pargv[i + 1] is: " << pargv[i+1]  << std::endl;
                  remID = atoi(pargv[i+1]);
                // std::cout << "remNotID: " << remNotID  << std::endl;
                  if (remID <= 0){
                      std::cout << REM_ID_WRONG_ID << pargv[i] << std::endl;
                      PROMT
                    }
                  if (i < *pargc)++i; // increased to skip remNotID input in next for loop iteration
              }
              else if(strcmp(pargv[i],"-o") == 0 && *pargc > i){
                      filename = (pargv[i + 1]);
                    std::cout << "Filename is: " << filename <<  endl;
                      if(!exists_test0 (filename)){
                          std::cout << FILE_NOT_EXIST <<std::endl;
                          PROMT
                      }
                    // std::cout << TRY_FILE << *filename<< std::endl;
                    // loadResult = xlang.load_file(*filename);
                    // PROMT // defined MACRO
                    if (i < *pargc)++i;// increased to skip remNotID input in next for loop iteration
              }
              else if (strcmp(pargv[i],"-n") == 0 && *pargc > i){
                      if (*pargc > (i + 1)){
                          txtstr = pargv[i+1]; // text has quotationsmarks then copy to varible
                          std::cout << "Text string: " << txtstr <<  endl;
                          PROMT
                      }
                      else{
                          std::cout << TEXT_MISSING << pargv[i] << std::endl;
                          PROMT
                      }
                      if (i < *pargc)++i;// increased to skip txtstr input in next for loop iteration
              }
              else if(strcmp(pargv[i],"-p") == 0) {
                      if(fileLoaded == true){
                         std::cout << "Debug - Calling print all -p: " << std::endl;
                         xlang.printall();}
                      else{
                          std::cout << FILE_NOT_LOAD << " : test"<< std::endl;}
              }
              else{
                ;
              }
            } // for loop for parsing command line input
              // std::cout << "Filename: " << *filename <<  endl;
              //std::cout << "remNotID: " << remNotID <<  endl;
            //std::cout << "addNotID: " << addNotID << "Text strig: " << txtstr <<  endl;
        } // -else
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
       if( fileLoaded == true  || (xlang.load_file(filename) == 0)) // file is loaded correctly
       {
         std::cout << "inside if xlang.load_file call" << std::endl;
          if (fileLoaded == false){
                  fileLoaded = true;}


          if (txtstr != nullptr){
              addNotID = xlang.find_last_notID();
              std::cout << NOT_NEW_ID_CONFIRM  << (++addNotID) << NOT_NEW_TXT_CONFIRM  << txtstr << std::endl;
              PROMT
              std::cout << YES_NO << endl;
              PROMT
              yesnoanswer = getchar();
             if (yesnoanswer == 'y'){
                 xlang.append_notification(txtstr);
             }
              txtstr = nullptr; // reset text string
          } // if (txtstr != nullptr)
          else{
              std::cout << NOT_NEW_ID_INSTR<< std::endl;
              std::cout << TEXT_NEW_ID_INSTR<< std::endl;
          }// else (txtstr != nullptr)

          if (remID  > 0 && xlang.ID_exists(remID)){ //Try to remove ID.
              xlang.remove_TextbyID(remID);
              remID = 0; 
          }
          else{ // ID not possible to remove
              std::cout << REM_ID_NOT_EXIST<< std::endl;
              remID = 0;
          }
        }//.xlang.Load file call

       
       std::cout << COMMANDS_DONE << std::endl;
        // commands called at initiation done. pointer now point to new command buffers
       pargv = newargv;
       pargc = &newargc;
       // Allocate memory for each string in teh tsring array.
        for (int i = 0; i < SIZE_ARRAY; i++) {
                newargv[i] = (char*)malloc((255 + 1)* sizeof(char));
                if (newargv[i] == NULL) {
                    cout << MEM_ALLOC_FAIL<< endl;
                return 1;
                }
        }// for allocate memory
        PROMT       
        *pargc = 0;
        std::cin.getline(cstr,256);
        PROMT
        std::cout << "Debug text after getline(cstr,256):  " << cstr << endl;
        PROMT
        if (strcmp(cstr,"exit" )!= 0 || strcmp(cstr,"-e" )!= 0 || strcmp(cstr,"bye") != 0 )
            parse_string(cstr, pargc, pargv);
        for(int i = 0; i < *pargc;++i){
            std::cout << "*pargv["<< i << "]" << pargv[i] << std::endl;}
   
    } //-do -while
    while(strcmp(cstr,"exit" ) != 0 && strcmp(cstr,"-e" ) != 0 && strcmp(cstr,"bye") != 0 );
    free(newargv);
    return 0;
}// main

inline bool exists_test0 (const std::string& name) {
                    ifstream f(name.c_str());
                      return f.good();
}

int parse_string(std::string str, int *pargc, char **pargv){
  std::cout << "Inside parse_string" << endl;
  std::string s;
  std::string stmp;
  int i = 0;
  bool found_1_cchar = false;
  
  std::stringstream ss(str); 

    // Use while loop to check the getline() function condition.  
    while (getline(ss, s, ' ')) {
        // str is used to store the token string while ' ' whitespace is used as the delimiter.
          std::cout << "i :" << i<< endl;
          if (s.find_first_of('"') != string::npos && found_1_cchar == false)
          {
              found_1_cchar = true;
              stmp.append(s + " ");
          } // found first quotation
          else if (s.find_first_of('"') == string::npos && found_1_cchar == true)
          {
              stmp.append(s + " ");
          }
          else if(s.find_first_of('"') != string::npos && found_1_cchar == true)
          {
              stmp.append(s);
              std::cout << "found 2nd quotation" << endl;
              strcpy(pargv[i], stmp.c_str());
              std::cout << "pargv"<<"["<<i<< "]: " << pargv[i] << endl;
              stmp.clear();
              found_1_cchar = false;
              ++i;
          }
          else{
              strcpy(pargv[i], s.c_str());
              std::cout << "pargv"<<"["<<i<< "]: " << pargv[i] << endl;
              ++i;
          }
          
         *pargc = i;
    }

    return 0;
}

