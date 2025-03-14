#pragma once

#include "Parser.h"
#include <vector>

class IntegerMatrixParser : public Parser
{
private:
	char _delimiter;
	std::vector<std::vector<int>> _data;
public:
	IntegerMatrixParser(char delimiter=' ');

	char getDelimiter() const;
	void setDelimiter(char delimiter);
	const std::vector<std::vector<int>>& getData() const;

	void parse(std::istream& in) override;
};

