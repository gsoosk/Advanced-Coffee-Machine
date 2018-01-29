#ifndef COFFE_MACHINE
#define COFFE_MACHINE
#include "Node.h"
#include <string>

class CoffeeMachine : public Node
{
public:
	CoffeeMachine(std::string _name, std::vector<Node*> _childs);
	virtual bool shouldBeExists(std::vector<std::string> membersOfConfiguration, Node* parent);	
};
#endif