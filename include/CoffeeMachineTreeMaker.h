#ifndef COOFFEE_MACHINE_TREE_MAKER
#define COOFFEE_MACHINE_TREE_MAKER 
#include <vector>
#include <string>
#include "CoffeeMachine.h"
#include "BadException.h"
#include "Node.h"
#include "Optional.h"
#include "Mandatory.h"
#include "Or.h"
#include "Alternative.h"
#include "Tools.h"

#define COFFEE_MACHINE_POS 0
#define COFFEE_MACHINE_NOT_FOUND_RETURN ""
#define SYMBOL_POS 3
#define SYMBOL_NOT_FOUND_RETURN ""
#define INDEPENDENT_SYMBOL "+"
#define ALTERNATIVE_SYMBOL "^"
#define OR_SYMBOL "|"
#define FIRST_NAME_POS 2
#define OPTIONAL_SYMBOL '?'
#define FEATURE_POS 0
#define FEATURE_NOT_FOUND_RETURN ""

class CoffeeMachineTreeMaker
{
public:
	CoffeeMachineTreeMaker();
	CoffeeMachine* makeNewCoffeMachine(std::vector<std::string> allNameAndSymbols);
	void addNewFeaturesToTree(std::vector<std::string> allNameAndSymbols, CoffeeMachine* ourCoffeeMachine);

private:
	std::string getNameOfCoffeeMachineFromAllNamesAndSymbols(std::vector<std::string> allNameAndSymbols);
	std::vector<Node*> getAllChildsFromAllNamesAndSymbols(std::vector<std::string> allNameAndSymbols);
	std::string getSymbolFromAllNamesAndSymbols(std::vector<std::string> allNameAndSymbols);
	std::vector<Node*> getIndependentChildsFromAllNameAndSymbols(std::vector<std::string> allNameAndSymbols);
	bool doesItOptional(std::string name);
	Optional* makeNewOptionalByName(std::string name);
	Mandatory* makeNewMandatoryByName(std::string name);
	std::vector<Node*> getAlternativeChildsFromAllNameAndSymbols(std::vector<std::string> allNameAndSymbols);
	Alternative* makeNewAlternativeByName(std::string name);
	std::vector<Node*> getOrChildsFromAllNameAndSymbols(std::vector<std::string> allNameAndSymbols);
	Or* makeNewOrByName(std::string name);
	std::string getNameOfFeatureFromAllNamesAndSymbols(std::vector<std::string> allNameAndSymbols);	
};
#endif