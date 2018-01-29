#ifndef DEPENDENT
#define DEPENDENT 
#include "Feature.h"
#include <string>
class Dependent : public Feature
{
public:
	Dependent(std::string _name);
	virtual bool shouldBeExists(std::vector<std::string> membersOfConfiguration, Node* parent) = 0;
};
#endif