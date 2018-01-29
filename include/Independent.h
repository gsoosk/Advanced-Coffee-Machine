#ifndef INDEPENDENT
#define INDEPENDENT 
#include "Feature.h"
#include <string>
class Independent : public Feature
{
public:
	Independent(std::string _name);
	virtual bool doesItDependent();
	virtual bool shouldBeExists(std::vector<std::string> membersOfConfiguration, Node* parent) = 0;
};
#endif