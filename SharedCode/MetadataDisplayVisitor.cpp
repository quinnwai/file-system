#pragma once
// definitions of metadata visitor here
#include <iostream>
#include "MetadataDisplayVisitor.h"

void MetadataDisplayVisitor::visit_textFile(TextFile* t) {
	std::cout << t->getName() << ' ';
	std::cout << "text" << ' ';
	std::cout << t->getSize() << std::endl;

}

void MetadataDisplayVisitor::visit_imageFile(ImageFile* i) {
	std::cout << i->getName() << ' ';
	std::cout << "image" << ' ';
	std::cout << i->getSize() << std::endl;
}