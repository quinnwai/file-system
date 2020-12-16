

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
		/*for () {

		}*/
		afs->closeFile(af);
		return success;
	}

	//else, print formatted
	AbstractFileVisitor* afv = new BasicDisplayVisitor();
	af->accept(afv);

	//TODO: why do we have to do this?
	delete afv;

	return success;
}
void DisplayCommand::displayInfo() {

}
