#ifndef MANDATORY
#define MANDATORY
#include "Independent.h"
#include <string>
class Mandatory : public Independent
{
public:
	Mandatory(std::string _name);
	virtual bool shouldBeExists(std::vector<std::string> membersOfConfiguration, Node* parent);
};
#endif