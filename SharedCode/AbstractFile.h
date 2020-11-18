#pragma once
#include<vector>
#include<string>
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

class AbstractFile {
public:
	virtual void read() = 0;
	virtual int write(std::vector<char> vec) = 0;
	virtual int append(std::vector<char> vec) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
};