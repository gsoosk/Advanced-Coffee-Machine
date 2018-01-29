#include "../include/Or.h"
using namespace std;

Or :: Or(string _name) : Dependent(_name)
{

}

bool Or :: shouldBeExists(vector<string> membersOfConfiguration, Node* parent)
{
	if(this -> existsInConfig(membersOfConfiguration))
		return true;
	for(int i = 0 ; i < membersOfConfiguration.size() ; i++)
	{
		if(parent -> doesHaveASpeceficChildByName(membersOfConfiguration[i]))
			return false;
	}
	return true;
}