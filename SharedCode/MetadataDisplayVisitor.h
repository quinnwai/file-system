#pragma once
// declaration of MetadataDisplayVisitor here
#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visit_textFile(TextFile* t) override;
	virtual void visit_imageFile(ImageFile* i) override;
};