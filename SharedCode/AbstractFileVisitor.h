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
	/*virtual void printTextMetadata(TextFile*) = 0;
	virtual void printImageMetadata(ImageFile*) = 0;*/
};