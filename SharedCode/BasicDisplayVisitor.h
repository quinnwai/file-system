#pragma once
// declaration of BasicDisplayVisitor here

#include "AbstractFileVisitor.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visit_textFile(TextFile* t) override;
	virtual void visit_imageFile(ImageFile* i) override;
};