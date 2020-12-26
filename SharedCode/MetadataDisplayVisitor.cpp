#pragma once
// definitions of metadata visitor here
#include <iostream>
#include "MetadataDisplayVisitor.h"

using namespace std;

void MetadataDisplayVisitor::visit_textFile(TextFile* t) {
	cout << t->getName() << ' ';
	cout << "text" << ' ';
	cout << t->getSize() << endl;

}

void MetadataDisplayVisitor::visit_imageFile(ImageFile* i) {
	cout << i->getName() << ' ';
	cout << "image" << ' ';
	cout << i->getSize() << endl;
}