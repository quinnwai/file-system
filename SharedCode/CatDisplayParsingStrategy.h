/*CatDisplayParsingStrategy.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration of the CatDisplayParsingStrategy, inherits from AbstractParsingStrategy
*/

#pragma once
#include "AbstractParsingStrategy.h"

class CatDisplayParsingStrategy : public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string) override;
	virtual void displayInfo() override;
};