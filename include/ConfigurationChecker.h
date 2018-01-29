#ifndef CONFIGURATION_CHECKER
#define CONFIGURATION_CHECKER
#include "CoffeeMachine.h"
class ConfigurationChecker
{
public:
	ConfigurationChecker();
	bool doesItValidConfig(std::vector<std::string> membersOfConfiguration, CoffeeMachine* ourCoffeeMachine);
private:
	//Private methods
	bool doesCoffeeMachineExists(std::vector<std::string> membersOfConfiguration, CoffeeMachine* ourCoffeeMachine);
	bool doesConfigMatchesWithCoffeeMachine(std::vector<std::string> membersOfConfiguration, CoffeeMachine* ourCoffeeMachine);
};
#endif