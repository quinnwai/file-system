/*RenameParsingStrategy.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration of the RenameParsingStrategy class, inherits from AbstractParsingStrategy
*/

#pragma once
#include "AbstractParsingStrategy.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string) override;
	virtual void displayInfo() override;
};