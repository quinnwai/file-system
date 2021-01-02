/*MetadataDisplayVisitor.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class implementation of a visitor that displays the metadata of files in the system
*/

#pragma once
#include <iostream>
#include "MetadataDisplayVisitor.h"

void MetadataDisplayVisitor::visit_textFile(TextFile* t) {
	std::cout << t->getName();
	for (int i = 0; i < 20 - t->getName().size(); ++i) {
		std::cout << ' ';
	}
	std::cout << "text";
	for (int i = 0; i < 6; ++i) {
		std::cout << ' ';
	}
	std::cout << t->getSize() << std::endl;

}

void MetadataDisplayVisitor::visit_imageFile(ImageFile* i) {
	std::cout << i->getName();
	for (int j = 0; j < 20 - i->getName().size(); ++j) {
		std::cout << ' ';
	}
	std::cout << "image";
	for (int i = 0; i < 5; ++i) {
		std::cout << ' ';
	}
	std::cout << i->getSize() << std::endl;
}