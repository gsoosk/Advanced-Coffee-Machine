#include "../include/Alternative.h"

using namespace std;

Alternative :: Alternative (string _name) : Dependent(_name)
{

}

bool Alternative :: shouldBeExists(vector<string> membersOfConfiguration, Node* parent)
{
	
	for(int i = 0 ; i < membersOfConfiguration.size() ; i++)
	{
		if(membersOfConfiguration[i] != name && parent -> doesHaveASpeceficChildByName(membersOfConfiguration[i]))
				return false;
	}
	return true;
	
}