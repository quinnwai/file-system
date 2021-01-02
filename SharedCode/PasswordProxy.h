/*PasswordProxy.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration of PasswordProxy class which defines password-protected file, inherits from AbstractFile
*/

#pragma once
#include "AbstractFile.h"
#include <string>

class PasswordProxy : public AbstractFile {
private:
	AbstractFile* protectedFile;
	std::string password;
public:
	PasswordProxy(AbstractFile*, std::string);
	~PasswordProxy();
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual int write(std::vector<char> info) override;
	virtual int append(std::vector<char> info) override;
	virtual std::vector<char> read() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string) override;

protected:
	std::string passwordPrompt();
	bool passwordPromptHelper(std::string);
};