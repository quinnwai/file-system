/*MetadataDisplayVisitor.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration of the MetadataDisplayVisitor class, inherits from AbstractFileVisitor
*/

#pragma once
// declaration of MetadataDisplayVisitor here
#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visit_textFile(TextFile* t) override;
	virtual void visit_imageFile(ImageFile* i) override;
};