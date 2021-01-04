/*ImageFile.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class implementation of the functionality of the ImageFile type
*/

#pragma once
#include "ImageFile.h"
#include "AbstractFileVisitor.h"
#include <iostream>
#include <vector>

ImageFile::ImageFile(std::string title) {
	image_size = 0;
	name = title;
}

unsigned int ImageFile::getSize() {
	if (image_size <= 0) {
		return 0;
	}
	return contents.size();
}

std::string ImageFile::getName() {
	return name;
}

int ImageFile::write(std::vector<char> info) {
	int temp_image_size = (int)(info[info.size() - 1]) - 48;

	for (int i = 0; i < info.size()-1; ++i) {
		if (info[i] != 'X' && info[i] != ' ') {
			std::cout << "error: invalid pixel" << std::endl;
			return invalid_pixel;
		}
	}
	if (info.size()-1 != (temp_image_size * temp_image_size)) {
		image_size = 0; 
		std::cout << "error: size mismatch" << std::endl;
		return size_mismatch;
	}

	//added to end to make sure the overwriting/changes to info member vector only happens for valid inputs
	image_size = temp_image_size;

	//clear contents before writing
	contents.clear();

	for (int i = 0; i < info.size() - 1; ++i) {
		contents.push_back(info[i]);
	}

	return success;
}

int ImageFile::append(std::vector<char> info) {
	std::cout << "no append allowed for image files" << std::endl;
	return no_append;
}

std::vector<char> ImageFile::read() {
	return contents;
}

void ImageFile::accept(AbstractFileVisitor* afv) {
	afv->visit_imageFile(this);
}

AbstractFile* ImageFile::clone(std::string str) {
	ImageFile* ifile = new ImageFile(*this);
	ifile->name = str + ".img";
	return ifile;
}

