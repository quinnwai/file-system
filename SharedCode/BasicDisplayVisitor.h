/*BasicDisplayVisitor.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration of basic file display, inherits from AbstractFileVisitor
*/

#pragma once
// declaration of BasicDisplayVisitor here

#include "AbstractFileVisitor.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visit_textFile(TextFile* t) override;
	virtual void visit_imageFile(ImageFile* i) override;
};