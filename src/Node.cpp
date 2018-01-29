#include "../include/Node.h"


using namespace std;

Node :: Node (string _name)
{
	name = _name;
}

Node* Node :: findChildByName(string childName)
{
	if(childs.size() == 0)
		return NULL ;
	for(int i = 0 ; i < childs.size() ; i++)
	{
		if(childs[i]->doesIt(childName))
			return childs[i];
		Node* returnFromChild = childs[i] -> findChildByName(childName);
		if(returnFromChild)
			return returnFromChild;
	}
	return NULL;
}

void Node :: addNewChildrens(std::vector<Node*> newChilds)
{
	for(int i = 0 ; i < newChilds.size() ; i++)
		childs.push_back(newChilds[i]);
}

bool Node :: doesIt(string _name)
{
	return name == _name;
}

bool Node :: doesItMatchWithConfig(vector<string> membersOfConfiguration)
{
	bool doesConditionsSatisfiedInTree = this -> doesConditionsSatisfiedInTree(membersOfConfiguration);
	vector<string> validConfig = this -> getValidConfigurationFromTree(membersOfConfiguration);
	if(Tools::doesTwoVectorOfStringsMatched(validConfig, membersOfConfiguration) && doesConditionsSatisfiedInTree)
		return true;
	return false;

}

bool Node :: doesConditionsSatisfiedInTree(vector<string> membersOfConfiguration)
{
	if(childs.size() == 0)
		return true;
	for(int i = 0 ; i < childs.size() ; i++)
	{
		if(childs[i] -> shouldBeExists(membersOfConfiguration, this))
		{
			if(!childs[i] -> existsInConfig(membersOfConfiguration))
				return false;
			if(!childs[i] -> doesConditionsSatisfiedInTree(membersOfConfiguration))
				return false;
		}
		else
			if(childs[i] -> existsInConfig(membersOfConfiguration))
				return false;
	}
	return true ;
}
vector<string> Node :: getValidConfigurationFromTree(vector<string> membersOfConfiguration)
{
	vector<string> validConfig;
	fillValidConfigurationFromTree(membersOfConfiguration, validConfig);
	return validConfig;
}
void Node :: fillValidConfigurationFromTree(vector<string> membersOfConfiguration , vector<string> &validConfig)
{
	validConfig.push_back(name);
	if(childs.size() == 0)
		return ;
	for(int i = 0 ; i < childs.size() ; i++)
	{
		if(childs[i] -> shouldBeExists(membersOfConfiguration, this))
		{
			if(!childs[i] -> existsInConfig(membersOfConfiguration))
				return ;
			childs[i] -> fillValidConfigurationFromTree(membersOfConfiguration, validConfig);
				
		}
		else
			if(childs[i] -> existsInConfig(membersOfConfiguration))
				return ;
	}
	return ;
}
bool Node :: existsInConfig(vector<string> membersOfConfiguration)
{
	return std::find(membersOfConfiguration.begin(), membersOfConfiguration.end(), name) != membersOfConfiguration.end();
}
bool Node :: doesHaveASpeceficChildByName(string name)
{
	for(int i = 0 ; i < childs.size(); i++)
		if(childs[i] -> doesIt(name))
			return true;
	return false;
}
Node :: ~Node()
{
	for(int i = 0 ; i < childs.size() ; i++)
		delete childs[i];
}