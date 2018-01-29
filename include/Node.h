#ifndef NOODE_H
#define NOODE_H 
#include <vector>
#include <string>
#include "Tools.h"

class Node
{
public:
	Node(std::string _name);
	Node* findChildByName(std::string childName);
	void addNewChildrens(std::vector<Node*> newChilds);
	bool doesIt(std::string _name);
	bool doesItMatchWithConfig(std::vector<std::string> membersOfConfiguration);
	bool existsInConfig(std::vector<std::string> membersOfConfiguration);
	bool doesConditionsSatisfiedInTree(std::vector<std::string> membersOfConfiguration);
	std::vector<std::string> getValidConfigurationFromTree(std::vector<std::string> membersOfConfiguration);
	void fillValidConfigurationFromTree(std::vector<std::string> membersOfConfiguration , std::vector<std::string> &validConfig);
	virtual bool shouldBeExists(std::vector<std::string> membersOfConfiguration, Node* parent) = 0 ;
	bool doesHaveASpeceficChildByName(std::string name);
	virtual ~Node();
	
protected:
	std::string name;
	std::vector<Node*> childs;

};


#endif