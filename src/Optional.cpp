#include "../include/Optional.h"

using namespace std;

Optional :: Optional(string _name) : Independent(_name)
{
	
}

bool Optional :: shouldBeExists(std::vector<std::string> membersOfConfiguration, Node* parent)
{
	return this -> existsInConfig(membersOfConfiguration);
}