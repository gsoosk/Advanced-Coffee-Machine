#include "../include/CommandHandler.h"
using namespace std;

CommandHandler :: CommandHandler()
{
	
}

void CommandHandler :: listenToCommands()
{
	while(true)
	{
		CoffeeMachine* ourCoffeeMachine;
		ourCoffeeMachine = this -> coffeeMachineInitializationHandeling();

		this -> addNewFeaturesCommandsFromUserHandeling(ourCoffeeMachine);

		this -> configurationCommandsFromUserCheck(ourCoffeeMachine);
	}
}


CoffeeMachine*  CommandHandler :: coffeeMachineInitializationHandeling()
{
	string firstCommandLine;
	getline (cin, firstCommandLine);
	CoffeeMachine*  ourCoffeeMachine;
	try{
		if(!this -> doesFeaturesCommandLineOk(firstCommandLine))
			throw BadException(CM_ERR);
		ourCoffeeMachine = this -> getCoffeeMachineFromCommand(firstCommandLine);
	}
	catch(BadException ex){
		ex.printMsg();
		ourCoffeeMachine = this -> coffeeMachineInitializationHandeling();
	}
	return ourCoffeeMachine;
}
bool CommandHandler :: doesFeaturesCommandLineOk(string line)
{
	bool equalExists = Tools :: doesStringContainsChar(line, COFFEE_MACHINE_EQUAL_SYMBOL[0]);
	bool featureSymbolExists = Tools :: doesStringContainsChar(line, INDEPENDENT_SYMBOL[0]) | Tools :: doesStringContainsChar(line, ALTERNATIVE_SYMBOL[0])
		| Tools :: doesStringContainsChar(line, OR_SYMBOL[0]);
	if(equalExists && featureSymbolExists)
		return true;
	return false;
}
void CommandHandler :: addNewFeaturesCommandsFromUserHandeling(CoffeeMachine* ourCoffeeMachine)
{
	string featuresCommandLine;
	getline (cin, featuresCommandLine);
	while(featuresCommandLine != FEATURES_COMMANDS_FINISHED_SIGN)
	{
		try{
			if(!this -> doesFeaturesCommandLineOk(featuresCommandLine))
				throw BadException(CM_ERR);	
			this -> addNewFeatures(featuresCommandLine, ourCoffeeMachine);
		}
		catch(BadException ex){
			ex.printMsg();
		}
		getline (cin, featuresCommandLine);
	}
}
void CommandHandler :: configurationCommandsFromUserCheck(CoffeeMachine* ourCoffeeMachine)
{
	string configCommandLine;
	getline (cin, configCommandLine);
	while(configCommandLine != CONFIGURATION_COMMANDS_FINISHED_SIGN)
	{
		try{
			if(!this -> doesConfigCommandLineOk(configCommandLine))
				throw BadException(CM_ERR);
			this -> checkConfigurationFromCommand(configCommandLine, ourCoffeeMachine);
		}
		catch(BadException ex){
			ex.printMsg();
		}
		getline (cin, configCommandLine);
	}
	cout << CONFIGURATION_COMMANDS_FINISHED_SIGN << endl;
}
bool CommandHandler :: doesConfigCommandLineOk(string line)
{
	bool openingBraceExists = Tools :: doesStringContainsChar(line, OPENING_BRACE_OF_CONFIG_LINE);
	bool closingBraceExists = Tools :: doesStringContainsChar(line, CLOSING_BRACE_OF_CONFIG_LINE);
	if(openingBraceExists && closingBraceExists)
		return true;
	return false;
}

CoffeeMachine* CommandHandler :: getCoffeeMachineFromCommand(string commandLine)
{
	vector<string> allNameAndSymbols = this -> getAllNameAndSymbolsFromCommandLine(commandLine);
	CoffeeMachineTreeMaker ourTreeMaker;
	return ourTreeMaker.makeNewCoffeMachine(allNameAndSymbols);
}

vector<string> CommandHandler :: getAllNameAndSymbolsFromCommandLine(string commandLine)
{
	commandLine = Tools :: removeAllSpaces(commandLine);
	vector<string> symbols ;
	symbols.push_back(OR_SYMBOL);
	symbols.push_back(ALTERNATIVE_SYMBOL);
	symbols.push_back(INDEPENDENT_SYMBOL);
	symbols.push_back(COFFEE_MACHINE_EQUAL_SYMBOL);
	return Tools :: splitBySymbols(commandLine, symbols); 

}

void CommandHandler :: addNewFeatures(string featuresCommandLine, CoffeeMachine* ourCoffeeMachine)
{
	vector<string> allNameAndSymbols = this -> getAllNameAndSymbolsFromCommandLine(featuresCommandLine);
	CoffeeMachineTreeMaker ourTreeMaker;
	ourTreeMaker.addNewFeaturesToTree(allNameAndSymbols, ourCoffeeMachine);
}


void CommandHandler :: checkConfigurationFromCommand(string configCommandLine, CoffeeMachine* ourCoffeeMachine)
{
	vector<string> membersOfConfiguration = Tools :: getMembersOfASet(configCommandLine);
	ConfigurationChecker ourConfigChecker;
	if(ourConfigChecker.doesItValidConfig(membersOfConfiguration, ourCoffeeMachine))
		cout << VALID_OUTPUT << endl;
	else
		cout << UNVALID_OUTPUT << endl;

}



