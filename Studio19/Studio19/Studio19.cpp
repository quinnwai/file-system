// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/MetadataDisplayVisitor.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	//set up
	AbstractFileVisitor* afv = new MetadataDisplayVisitor;
	AbstractFileVisitor* bdv = new BasicDisplayVisitor;
	ImageFile iFile = ImageFile("iFile.img");
	iFile.write({ 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' });
	TextFile tFile = TextFile("tFile.txt");
	tFile.write({ 'h', 'e', 'l', 'l', 'o', ' ', 'f', 'r', 'i', 'e', 'n', 'd' });

	//accept to print out file contents
	iFile.accept(afv);
	tFile.accept(afv);

	return success;
}
