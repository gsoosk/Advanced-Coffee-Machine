#ifndef COMMAND_HANDLER
#define COMMAND_HANDLER
#include "CoffeeMachine.h"
#include <string>
#include "Tools.h"
#include <iostream>
#include "BadException.h"
#include "ConfigurationChecker.h"
#include "CoffeeMachineTreeMaker.h"

#define INDEPENDENT_SYMBOL "+"
#define ALTERNATIVE_SYMBOL "^"
#define OR_SYMBOL "|"
#define OPTIONAL_SYMBOL '?'
#define COFFEE_MACHINE_EQUAL_SYMBOL "="
#define FEATURE_NOT_FOUND_RETURN ""
#define VALID_OUTPUT "Valid"
#define UNVALID_OUTPUT "Invalid"
#define FEATURES_COMMANDS_FINISHED_SIGN "#"
#define CONFIGURATION_COMMANDS_FINISHED_SIGN "##"
#define OUTPUT_FINISHED_SYMBOL "##"
#define OPENING_BRACE_OF_CONFIG_LINE '{'
#define CLOSING_BRACE_OF_CONFIG_LINE '}'

class CommandHandler
{
public:
	CommandHandler();
	void listenToCommands();
	CoffeeMachine* getCoffeeMachineFromCommand(std::string commandLine);
	void addNewFeatures(std::string featuresCommandLine, CoffeeMachine* ourCoffeeMachine);
	void checkConfigurationFromCommand(std::string configCommandLine, CoffeeMachine* ourCoffeeMachine);
private:
	//Private methods :
	CoffeeMachine* coffeeMachineInitializationHandeling();
	void addNewFeaturesCommandsFromUserHandeling(CoffeeMachine* ourCoffeeMachine);
	void configurationCommandsFromUserCheck(CoffeeMachine* ourCoffeeMachine);
	std::vector<std::string> getAllNameAndSymbolsFromCommandLine(std::string commandLine);
	bool doesFeaturesCommandLineOk(std::string line);
	bool doesConfigCommandLineOk(std:: string line);

};
#endif