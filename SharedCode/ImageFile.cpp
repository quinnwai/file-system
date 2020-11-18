// definition of ImageFile class here
#pragma once
#include "ImageFile.h"
#include "AbstractFile.h"
#include <iostream>
using namespace std;

ImageFile::ImageFile(string title) {
	image_size = 0;
	name = title;
}

unsigned int ImageFile::getSize() {
	cout << image_size << endl;
	return image_size;
}

string ImageFile::getName() {
	cout << name << endl;
	return name;
}

int ImageFile::write(vector<char> info) {
	swap(info, this->contents);
	for (char c : this->contents) {
		if (c != 'X') {
			cout << "error: invalid pixel" << endl;
			return invalid_pixel;
		}
		else if (c != ' ') {
			cout << "error: invalid pixel" << endl;
			return invalid_pixel;
		}
	}
	image_size = this->contents[this->contents.size() - 1]; 
	if ((this->contents).size() != (((int)(image_size)-48) * ((int)(image_size)-48)) + 1) {
		cout << "error: size mismatch" << endl;
		return size_mismatch;
	}
	cout << image_size << endl;
	return success;
}

int ImageFile::append(vector<char> info) {
	cout << "no append" << endl;
	return no_append;
}

void ImageFile::read() {
	for (int y = ((int)image_size)-48; y > 0; --y) {
		for (int x = 0; y < ((int)image_size)-48; ++x) {
			cout << this->contents[(y-1) * ((int)(image_size)-48) + x];
		}
		cout << endl;
	}
	cout << "file read, GREAT SUCCESS" << endl;
}

