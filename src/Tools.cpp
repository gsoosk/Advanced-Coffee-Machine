#include "../include/Tools.h"
using namespace std;

vector<string> Tools :: splitBySpace(string line)
{
	return Tools::splitByCharacter(line, ' ');
}

vector<string> Tools :: splitByCharacter (string line, char character)
{
	vector<string> output;
	bool there_is_char = Tools :: doesStringContainsChar(line, character);
	while(there_is_char == true)
	{
		int characterPosition = line.find(character);
		string subString = line.substr(0,characterPosition);
		string newLine = line.substr(characterPosition+1);
		line = newLine;
		if(subString != EMPTY_STRING)
			output.push_back(subString);
		there_is_char = (line.find(character) != string::npos);
	} 
	if(line != EMPTY_STRING)
		output.push_back(line);
	return output;
}

vector<string> Tools :: getMembersOfASet(string line)
{
	line = line.substr(1, line.size() - 2);
	line = Tools :: removeAllSpaces(line);
	return Tools::splitByCharacter(line, ',');
}

bool Tools :: doesTwoVectorOfStringsMatched(vector<string> valid, vector<string> toCheck)
{
	for(int i = 0 ; i < toCheck.size(); i++)
	{
		if(std::find(valid.begin(), valid.end(), toCheck[i]) == valid.end())
			return false ;
	}
	return true;
}
string Tools :: removeAllSpaces(string line)
{
	line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
	return line;
}
vector<string> Tools :: splitBySymbols(string line, vector<string> symbols)
{
	vector<string> output;
	string subStr = "";
	for(int i = 0 ; i < line.size() ; i++)
	{
		string currentChar(1, line[i]);
		bool itWasSymbol = false;
		for (int j = 0; j < symbols.size(); j++)
			if(symbols[j] == currentChar)
			{
				output.push_back(subStr);
				subStr = "";
				output.push_back(symbols[j]);
				itWasSymbol = true ;
				break ;
			}
		if(!itWasSymbol)
			subStr += currentChar;
	}
	output.push_back(subStr);
	return output;
}
bool Tools :: doesStringContainsChar(string line, char character)
{
	size_t found = line.find(character);
	return (found != string::npos);
}