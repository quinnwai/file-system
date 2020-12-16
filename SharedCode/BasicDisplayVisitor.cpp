// definitions of basic display visitor here
#pragma once
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <vector>

using namespace std;

void BasicDisplayVisitor::visit_textFile(TextFile* t) {
	vector<char> vec = t->read();

	//iterate through characters and print out in order
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i];
	}
	cout << endl;
}

void BasicDisplayVisitor::visit_imageFile(ImageFile* i) {
	//store relevant variables for future use
	vector<char> vec = i->read();
	int width = sqrt(i->getSize());

	//iterate through from top to bottom to print image file
	for (int y = width; y > 0; --y) {
		for (int x = 0; x < width; ++x) {
			cout << vec[(y - 1) * width + x];
		}
		cout << endl;
	}
}
