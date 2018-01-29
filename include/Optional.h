#ifndef OPTIONAL
#define OPTIONAL 
#include "Independent.h"
#include <string>
class Optional : public Independent
{
public:
	Optional(std::string _name);
	virtual bool shouldBeExists(std::vector<std::string> membersOfConfiguration, Node* parent);
};
#endif