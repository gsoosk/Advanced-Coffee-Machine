#include "../include/CoffeeMachine.h"
using namespace std;
 
CoffeeMachine :: CoffeeMachine(string _name, vector<Node*> _childs) : Node(_name)
{
	childs = _childs ;
}
 bool CoffeeMachine :: shouldBeExists(std::vector<std::string> membersOfConfiguration, Node* parent)
 {
 	return true;
 }
	