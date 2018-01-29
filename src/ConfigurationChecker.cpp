#include "../include/ConfigurationChecker.h"
using namespace std;

ConfigurationChecker :: ConfigurationChecker ()
{
	
}

bool ConfigurationChecker :: doesItValidConfig(vector<string> membersOfConfiguration, CoffeeMachine* ourCoffeeMachine)
{
	bool coffeeMachineExists = this -> doesCoffeeMachineExists(membersOfConfiguration, ourCoffeeMachine);
	bool configMatchesWithCoffeeMachine = this -> doesConfigMatchesWithCoffeeMachine(membersOfConfiguration, ourCoffeeMachine);
	if(coffeeMachineExists && configMatchesWithCoffeeMachine)
		return true;
	return false;
}

bool ConfigurationChecker :: doesCoffeeMachineExists(vector<string> membersOfConfiguration, CoffeeMachine* ourCoffeeMachine)
{
	for(int i = 0 ; i < membersOfConfiguration.size() ; i++)
	{
		if(ourCoffeeMachine -> doesIt(membersOfConfiguration[i]))
			return true;
	}
	return false;
}

bool ConfigurationChecker :: doesConfigMatchesWithCoffeeMachine(vector<string> membersOfConfiguration, CoffeeMachine* ourCoffeeMachine)
{
	return ourCoffeeMachine -> doesItMatchWithConfig(membersOfConfiguration);
}
