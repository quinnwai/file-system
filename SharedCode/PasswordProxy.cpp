#pragma once
#include "PasswordProxy.h"
#include <iostream>
#include <vector>

using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* af, string s) : protectedFile(af), password(s) {}

PasswordProxy::~PasswordProxy() {
	delete protectedFile;
}

string PasswordProxy::passwordPrompt() {
	string p;
	cout << "please input your password" << endl;
	cin >> p;
	return p;
}

bool PasswordProxy::passwordPromptHelper(std::string s) {
	return s == password;
}

//TODO: some sort of test issue w/ assert error
vector<char> PasswordProxy::read() {
	if (passwordPromptHelper(passwordPrompt())) {
		//cout << "success" << endl;
		return protectedFile->read();
	}
	//cout << "failure" << endl;
	return vector<char>();
}

int PasswordProxy::write(vector<char> info) {
	if (passwordPromptHelper(passwordPrompt())) {
		return protectedFile->write(info);
	}
	return incorrect_password;
}

int PasswordProxy::append(std::vector<char> info) {
	if (passwordPromptHelper(passwordPrompt())) {
		return protectedFile->append(info);
	}
	return incorrect_password;
}

unsigned int PasswordProxy::getSize() {
	return protectedFile->getSize();
}

string PasswordProxy::getName() {
	return protectedFile->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* afv) {
	if (passwordPromptHelper(passwordPrompt())) {
		protectedFile->accept(afv);
	}
}

AbstractFile* PasswordProxy::clone(std::string str) { // not sure if this is correct
	PasswordProxy* pfile = new PasswordProxy(*this);
	AbstractFile* copy = pfile->protectedFile->clone(str);
	pfile->protectedFile = copy;
	return pfile;
}
