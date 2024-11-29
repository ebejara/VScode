//============================================================================
// Name        : pointer_tests.cpp
// Author      : EB
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

char elem[6] = {'a','b','c','d','e','f'};

char* epointer = &elem[0];
char *epointer2 = &elem[0];
char *adr1 = &elem[0];
char *adr2 = &elem[1];
char *epointer3;




int main() {


epointer3 = &elem[3];

if (epointer == epointer2)
	cout << "epointer == epointer2" << endl; // prints
else
	cout << "epointer != epointer2" << endl; // prints

cout << "adr1: " << adr1 << endl; // prints
cout << "*adr1: " << *adr1 << endl; // prints
cout << "adr2: " << adr2 << endl; // prints
cout << "*adr2:" << *adr2 << endl; // prints

cout << "&adr1: " << &adr1 << endl; // prints
cout << "&adr2:" << &adr2 << endl; // prints

cout << "epointer3: " << epointer3 << endl; // prints


return 0;
}
