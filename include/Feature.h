#ifndef FEATURE
#define FEATURE 
#include "Node.h"
#include <string>
class Feature : public Node
{
public:
	Feature(std::string _name);
	virtual bool shouldBeExists(std::vector<std::string> membersOfConfiguration, Node* parent) = 0;
};
#endif