/*TextFile.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class implementation of a the TextFile type
*/

#pragma once
#include "TextFile.h"
#include "AbstractFileVisitor.h"
#include<string>
#include<iostream>
#include <vector>

//constructor using given string as file name
TextFile::TextFile(std::string str) : fileName(str) {
//	cout << "textFile constructor" << endl;
}

//get size of 'contents' vector
unsigned int TextFile::getSize() {
//	cout << "size: " << contents.size() << endl;
	return (unsigned int) contents.size();
}

//get file name from private member variable 'fileName'
std::string TextFile::getName() {
//	cout << "FileName: " << fileName << endl;
	return fileName;
}

int TextFile::write(std::vector<char> vec) {
	swap(vec, this->contents);

	//test methods
	//for (char c : this->contents) {
	//	cout << c;
	//}
	//cout << endl;
//	cout << "vector swapped" << endl;
	return success;
}

int TextFile::append(std::vector<char> vec) {
	//cout << "appending vector..." << endl;
	for (char c : vec) {
		this->contents.push_back(c);
		//cout << c;
	}
	//cout << endl;
	return success;
}

std::vector<char> TextFile::read() {
	//cout << "contents read" << endl;
	return contents;
}

void TextFile::accept(AbstractFileVisitor* afv) {
	afv->visit_textFile(this);
}

AbstractFile* TextFile::clone(std::string str) {
	TextFile* tfile = new TextFile(*this);
	tfile->fileName = str + ".txt";
	return tfile;
}
