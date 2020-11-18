#pragma once
#include "TextFile.h"
#include<string>
#include<iostream>

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
	//TODO: make sure this works and errors caught
	swap(vec, this->contents);
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

void TextFile::read() {
	for (char c : this->contents) {
		cout << c;
	}
	cout << endl;
}

