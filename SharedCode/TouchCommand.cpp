/*CatCommand.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class implementation of a command that enables a user to add files to the system.
*/

#pragma once
#include "TouchCommand.h"
#include <string>
#include <iostream>
#include "PasswordProxy.h"

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* afs1, AbstractFileFactory* aff1) : afs(afs1), aff(aff1) {}

int TouchCommand::execute(string str) {
	if (str.substr(str.length() - 2) == "-p") {
		string str2;
		for (int i = 0; i < str.length() - 3; ++i) {
			str2[i] = str[i];
		}
		AbstractFile* af = aff->createFile(str2);
		cout << "enter a password" << endl;
		string password;
		cin >> password;
		AbstractFile* pfile = new PasswordProxy(af, password); // huh? this is the big issue
		if (!pfile) {
			cout << "cannot create file" << endl;
			return cannot_create_file;
		}
		int add_result = afs->addFile(str2, pfile);
		if (add_result == 0) {
			return success;
		}
		else {
			delete pfile;
			cout << "unable to add file" << endl;
			return add_result;
		}
	}
	else {
		AbstractFile* af = aff->createFile(str);
		if (af) {
			int add_result = afs->addFile(str, af);
			if (add_result == 0) {
				return success;
			}
			else {
				delete af;
				cout << "unable to add file" << endl;
				return add_result;
			}
		}
		else {
			cout << "cannot create file" << endl;
			return cannot_create_file;
		}
	}
}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command : touch <filename>" << endl;
}