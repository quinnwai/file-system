// definition of ImageFile class here
#pragma once
#include "ImageFile.h"
#include "AbstractFileVisitor.h"
#include <iostream>
#include <vector>

using namespace std;

ImageFile::ImageFile(string title) {
	cout << "image constructor" << endl;
	image_size = 0;
	name = title;
}

unsigned int ImageFile::getSize() {
	//cout << image_size-48 << endl;
	if (image_size < 48) {
		return 0;
	}
	return (image_size-48)*(image_size - 48); //TODO: make sure this is correct
}

string ImageFile::getName() {
	//cout << name << endl;
	return name;
}

int ImageFile::write(vector<char> info) { // ERROR HERE
	swap(info, this->contents);
	for (int i = 0; i < this->contents.size() - 1; ++i) {
		if (this->contents[i] != 'X' && this->contents[i] != ' ') {
			cout << "error: invalid pixel" << endl;
			return invalid_pixel;
		}
	}
	image_size = this->contents[this->contents.size() - 1]; 
	if ((this->contents).size() != (((int)(image_size)-48) * ((int)(image_size)-48)) + 1) {
		image_size = '0'; 
		cout << "error: size mismatch" << endl;
		return size_mismatch;
	}
	//cout << "successful image write" << endl;
	return success;
}

int ImageFile::append(vector<char> info) {
	cout << "no append" << endl;
	return no_append;
}

vector<char> ImageFile::read() { 
	//cout << "image read" << endl;
	return contents;
}

void ImageFile::accept(AbstractFileVisitor* afv) {
	afv->visit_imageFile(this);
	//afv->printImageMetadata(this);
}
