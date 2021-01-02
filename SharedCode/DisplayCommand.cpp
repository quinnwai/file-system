

#pragma once
#include "DisplayCommand.h"
#include "BasicDisplayVisitor.h"
#include <sstream>
#include <iostream>

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* afs_) : afs(afs_) {}

int DisplayCommand::execute(string str) {
	//extract from ss to see if first word (file name) can be opened
	istringstream iss(str);
	string fileName;
	iss >> fileName;

	AbstractFile* af = afs->openFile(fileName);

	//if it is a nullptr, then file does not exist. Else, look for second word
	if (!af) {
		cout << "no such file exists" << endl;
		return no_file_exists;
	}

	//extract again to see if an "-d" was used. If so, print out unformatted. Else print formatted
	string format;
	iss >> format;

	if (format == "-d") { //unformatted
		vector<char> vec = af->read();
		for (char c : vec) {
			cout << c;
		}
		cout << endl;
		afs->closeFile(af);
		return success;
	}

	//else, print formatted
	AbstractFileVisitor* afv = new BasicDisplayVisitor();
	af->accept(afv);

	//TODO: why do we have to do this specifically? Is it always for new? (as opposed to main... or is main wrong)
	delete afv;

	afs->closeFile(af);
	return success;
}
void DisplayCommand::displayInfo() {
	cout << "ds displays a file's contents" << endl;
	cout << "ds can be invoked with the command : ds <filename> [-d]" << endl;;
	cout << "Use -d to show a unformatted version or leave out -d to show a formatted version" << endl;
}