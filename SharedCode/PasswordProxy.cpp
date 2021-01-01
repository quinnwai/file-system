#pragma once
#include "PasswordProxy.h"
#include <iostream>
#include <vector>

PasswordProxy::PasswordProxy(AbstractFile* af, std::string s) : protectedFile(af), password(s) {}

PasswordProxy::~PasswordProxy() {
	delete protectedFile;
}

std::string PasswordProxy::passwordPrompt() {
	std::string p;
	std::cout << "please input your password" << std::endl;
	std::cin >> p;
	return p;
}

bool PasswordProxy::passwordPromptHelper(std::string s) {
	return s == password;
}

//TODO: some sort of test issue w/ assert error
std::vector<char> PasswordProxy::read() {
	if (passwordPromptHelper(passwordPrompt())) {
		//cout << "success" << endl;
		return protectedFile->read();
	}
	//cout << "failure" << endl;
	return std:: vector<char>();
}

int PasswordProxy::write(std::vector<char> info) {
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

std::string PasswordProxy::getName() {
	return protectedFile->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* afv) {
	if (passwordPromptHelper(passwordPrompt())) {
		protectedFile->accept(afv);
	}
}

AbstractFile* PasswordProxy::clone(std::string str) {
	PasswordProxy* pfile = new PasswordProxy(*this);
	AbstractFile* copy = pfile->protectedFile->clone(str);
	pfile->protectedFile = copy;
	return pfile;
}
