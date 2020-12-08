// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once

#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include <iostream>

using namespace std;

int main()
{
	AbstractFileFactory* a = new SimpleFileFactory();
	AbstractFileSystem* b = new SimpleFileSystem();

	string uno = "uno.txt";
	string dos = "dos.img";
	string tres = "empty";
	
	AbstractFile* tresdoc;
	AbstractFile* dospic = a->createFile(dos);
	
	cout << b->addFile(uno, a->createFile(uno)) << endl;
	cout << b->addFile(dos, dospic) << endl;
	cout << b->addFile(dos, dospic) << endl;
	cout << dospic << endl;
	cout << b->openFile(dos) << endl;
	cout << b->openFile(dos) << endl;
	cout << b->deleteFile(dos) << endl;
	cout << b->closeFile(dospic) << endl;
	cout << b->deleteFile(uno) << endl;
	cout << b->deleteFile(dos) << endl;
	cout << b->closeFile(dospic) << endl;
	cout << b->deleteFile(tres) << endl;
	cout << b->openFile(tres) << endl;
	return 0;
}
