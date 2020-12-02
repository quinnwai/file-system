#pragma once
// declaration of the file visitor interface here
#include <vector>
#include <string>

class TextFile {
private:
	std::vector<char> contents;
	std::string fileName;
};
class ImageFile {
	std::string name;
	std::vector<char> contents;
	char image_size;
};

class AbstractFileVisitor {
public:
	virtual void visit_textFile(TextFile*) = 0;
	virtual void visit_imageFile(ImageFile*) = 0;
};