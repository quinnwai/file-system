#pragma once
#include "TextFile.h"
#include<string>
#include<iostream>
#include <vector>

using namespace std;
//  Define the TextFile class here

//constructor using given string as file name
TextFile::TextFile(string str) : fileName(str) {
	cout << "textFile constructor" << endl;
}

//get size of 'contents' vector
unsigned int TextFile::getSize() {
	cout << "size: " << contents.size() << endl;
	return (unsigned int) contents.size();
}

//get file name from private member variable 'fileName'
string TextFile::getName() {
	cout << "FileName: " << fileName << endl;
	return fileName;
}

int TextFile::write(std::vector<char> vec) {
	swap(vec, this->contents);

	//test methods
	for (char c : this->contents) {
		cout << c;
	}
	cout << endl;
	cout << "vector swapped" << endl;
	return 0;
}

int TextFile::append(std::vector<char> vec) {
	for (char c : vec) {
		this->contents.push_back(c);
		cout << c;
	}
	cout << endl;
	return 0;
}

vector<char> TextFile::read() {
	cout << "ur so smart" << endl;
	return contents;
}

void TextFile::accept(AbstractFileVisitor* afv) {
	//TODO: why is it undefined type (how to access member vars w/out circular inclusions)
	afv->visit_textFile(this);
}
