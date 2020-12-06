// definitions of basic display visitor here
#pragma once
#include "BasicDisplayVisitor.h"
#include <iostream>

using namespace std;

void BasicDisplayVisitor::visit_textFile(TextFile* t) {
	//TODO: make sure variables accessible w/out circular inclusion (friendship?)
	
	for (char c : t->contents) {
		cout << c;
	}
	cout << endl;
}

void BasicDisplayVisitor::visit_imageFile(ImageFile* i) {
	//TODO: make sure variables accessible

	/*for (int y = (i->getSize()) - 48; y > 0; --y) {
		for (int x = 0; x < ((int)image_size) - 48; ++x) {
			cout << this->contents[(y - 1) * (image_size - 48) + x];
		}
		cout << endl;
	}*/
}
