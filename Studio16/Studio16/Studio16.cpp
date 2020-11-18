// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\AbstractFile.h"
#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
	AbstractFile* af = new TextFile("str"); //dynamically allocate and passed back as parameters

	//TODO: call all the functions as tests
	
	return 0;
}


