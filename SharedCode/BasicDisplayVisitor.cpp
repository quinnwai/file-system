// definitions of basic display visitor here
#pragma once
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <vector>

void BasicDisplayVisitor::visit_textFile(TextFile* t) {
	std::vector<char> vec = t->read();

	//iterate through characters and print out in order
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i];
	}
	std::cout << std::endl;
}

void BasicDisplayVisitor::visit_imageFile(ImageFile* i) {
	//store relevant variables for future use
	std::vector<char> vec = i->read();
	int width = sqrt(i->getSize());

	//iterate through from top to bottom to print image file
	for (int y = width; y > 0; --y) {
		for (int x = 0; x < width; ++x) {
			std::cout << vec[(y - 1) * width + x];
		}
		std::cout << std::endl;
	}
}
