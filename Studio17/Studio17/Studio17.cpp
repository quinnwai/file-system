// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include "..\..\\SharedCode\AbstractFile.h"
#include "..\..\\SharedCode\ImageFile.h"
using namespace std;


int main(int argc, char*argv[])
{
	string pic = "pic";
	AbstractFile* file = new ImageFile(pic);
	file->append({ 'A', 'B', 'C' });
	file->getName();
	file->getSize();
	file->read();
	file->write({ 'X', ' ', ' ', 'X', '2' });
	file->write({ 'X', ' ', 'A', 'B', '2' });
	file->write({ 'X', ' ', ' ', 'X', 'X', ' ', ' ', 'X', ' ', '3' });
}

