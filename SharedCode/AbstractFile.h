#pragma once
#include<vector>
#include<string>
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

enum returns { success, invalid_pixel, size_mismatch, no_append, no_file_exists, already_open, already_exists, invalid_file, unopened_file };

class AbstractFile {
public:
	virtual ~AbstractFile() = default;
	virtual void read() = 0;
	virtual int write(std::vector<char> vec) = 0;
	virtual int append(std::vector<char> vec) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
};


