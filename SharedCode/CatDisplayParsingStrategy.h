#pragma once
#include "AbstractParsingStrategy.h"

class CatDisplayParsingStrategy : public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string) override;
};