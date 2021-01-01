/*TouchCommand.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class implementation of a command that enables a user to add files to the system.
*/

#pragma once
#include "TouchCommand.h"
#include <string>
#include <iostream>
#include "PasswordProxy.h"

TouchCommand::TouchCommand(AbstractFileSystem* afs1, AbstractFileFactory* aff1) : afs(afs1), aff(aff1) {}

int TouchCommand::execute(std::string str) {
	if (str.substr(str.length() - 2) == "-p") { // checks to see if password-protected file
		str.pop_back();
		str.pop_back();
		str.pop_back(); // deletes " -p"
		AbstractFile* af = aff->createFile(str); // creates file with given name
		std::cout << "enter a password" << std::endl;
		std::string password;
		std::cin >> password; // collects user-inputted password
		AbstractFile* pfile = new PasswordProxy(af, password); // creates password-protected file with given file and password
		if (pfile) {
			int add_result = afs->addFile(str, pfile);
			if (add_result == 0) {
				return success;
			}
			else {
				delete pfile;
				std::cout << "unable to add file" << std::endl;
				return add_result;
			}
		}
		else {
			std::cout << "cannot create file" << std::endl;
			return cannot_create_file;
		}
	}
	else { // not a password-protected file
		AbstractFile* af = aff->createFile(str);
		if (af) {
			int add_result = afs->addFile(str, af);
			if (add_result == 0) {
				return success;
			}
			else {
				delete af;
				std::cout << "unable to add file" << std::endl;
				return add_result;
			}
		}
		else {
			std::cout << "cannot create file" << std::endl;
			return cannot_create_file;
		}
	}
}

void TouchCommand::displayInfo() {
	std::cout << "touch creates a file, touch can be invoked with the command : touch <filename>" << std::endl;
}