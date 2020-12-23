// definition of ImageFile class here
#pragma once
#include "ImageFile.h"
#include "AbstractFileVisitor.h"
#include <iostream>
#include <vector>

using namespace std;

ImageFile::ImageFile(string title) {
//	cout << "image constructor" << endl;
	image_size = 0;
	name = title;
}

unsigned int ImageFile::getSize() {
	//cout << image_size-48 << endl;
	if (image_size <= 0) {
		return 0;
	}
	return contents.size(); //TODO: make sure this is correct
}

string ImageFile::getName() {
	//cout << name << endl;
	return name;
}

int ImageFile::write(vector<char> info) { // ERROR HERE
	//image_size = info.pop_back();
	//swap(info, this->contents);

	int temp_image_size = (int)(info[info.size() - 1]) - 48;

	for (int i = 0; i < info.size()-1; ++i) {
		if (info[i] != 'X' && info[i] != ' ') {
			cout << "error: invalid pixel" << endl;
			return invalid_pixel;
		}
	}
	if (info.size()-1 != (temp_image_size * temp_image_size)) {
		image_size = 0; 
		cout << "error: size mismatch" << endl;
		return size_mismatch;
	}
	//cout << "successful image write" << endl;

	//FWL: swapped around push_back for write so that it only overwrites file if it's a valid input
	//added to end to make sure the overwriting/changes to info member vector only happens for valid inputs
	image_size = temp_image_size;

	for (int i = 0; i < info.size() - 1; ++i) {
		contents.push_back(info[i]);
	}

	return success;
}

int ImageFile::append(vector<char> info) {
	cout << "no append allowed for image files" << endl;
	return no_append;
}

vector<char> ImageFile::read() { 
	//cout << "image read" << endl;

	return contents;
}

void ImageFile::accept(AbstractFileVisitor* afv) {
	afv->visit_imageFile(this);
}

AbstractFile* ImageFile::clone(string str) {
	ImageFile* ifile = new ImageFile(*this);
	ifile->name = str + ".img";
	return ifile;
}

