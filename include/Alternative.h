#ifndef ALTERNATIVE
#define ALTERNATIVE 
#include "Dependent.h"
#include <string>
class Alternative : public Dependent
{
public:
	Alternative(std::string _name);
	virtual bool shouldBeExists(std::vector<std::string> membersOfConfiguration, Node* parent);
};
#endif