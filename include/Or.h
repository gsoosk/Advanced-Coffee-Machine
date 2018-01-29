#ifndef OR
#define OR 
#include "Dependent.h"

class Or : public Dependent
{
public:
	Or(std::string _name);
	virtual bool shouldBeExists(std::vector<std::string> membersOfConfiguration, Node* parent);
};
#endif