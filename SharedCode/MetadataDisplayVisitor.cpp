#pragma once
// definitions of metadata visitor here
#include <iostream>
#include "MetadataDisplayVisitor.h"

using namespace std;

void MetadataDisplayVisitor::visit_textFile(TextFile* t) {
	cout << t->getName() << endl;
	cout << t->getSize() << endl;
	cout << "text" << endl;
}

void MetadataDisplayVisitor::visit_imageFile(ImageFile* i) {
	cout << i->getName() << endl;
	cout << i->getSize() << endl;
	cout << "image" << endl;
}