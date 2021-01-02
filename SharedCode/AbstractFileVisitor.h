/*AbstractFileVisitor.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class implementation of a command that enables a user to add files to the system.
*/

#pragma once
// declaration of the file visitor interface here
#include <vector>
#include <string>
#include "TextFile.h"
#include "ImageFile.h"

class AbstractFileVisitor {
public:
	virtual void visit_textFile(TextFile*) = 0;
	virtual void visit_imageFile(ImageFile*) = 0;
};