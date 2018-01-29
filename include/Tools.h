#ifndef TOOLS
#define TOOLS
#include <string>
#include <vector>
#define EMPTY_STRING ""
class Tools
{
public:
	static std::vector<std::string> splitBySpace(std::string line);
	static std::vector<std::string> splitByCharacter(std::string line, char character);
	static std::vector<std::string> getMembersOfASet(std::string line);
	static bool doesTwoVectorOfStringsMatched(std::vector<std::string> valid, std::vector<std::string> toCheck);
	static std::string removeAllSpaces(std::string);
	static std::vector<std::string> splitBySymbols(std::string line, std::vector<std::string> symbols);
	static bool doesStringContainsChar(std::string line, char character);
};
#endif