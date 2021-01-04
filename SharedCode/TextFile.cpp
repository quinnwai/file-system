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
TextFile::TextFile(std::string str) : fileName(str) {}

//get size of 'contents' vector
unsigned int TextFile::getSize() {
	return (unsigned int) contents.size();
}

//get file name from private member variable 'fileName'
std::string TextFile::getName() {
	return fileName;
}

int TextFile::write(std::vector<char> vec) {
	swap(vec, this->contents);
	return success;
}

int TextFile::append(std::vector<char> vec) {
	for (char c : vec) {
		this->contents.push_back(c);
	}
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
