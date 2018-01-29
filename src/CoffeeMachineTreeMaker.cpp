#include "../include/CoffeeMachineTreeMaker.h"
using namespace std;

CoffeeMachineTreeMaker :: CoffeeMachineTreeMaker()
{

}
CoffeeMachine* CoffeeMachineTreeMaker :: makeNewCoffeMachine(std::vector<string> allNameAndSymbols)
{
	string coffeeMachineName = this -> getNameOfCoffeeMachineFromAllNamesAndSymbols(allNameAndSymbols);
	vector<Node*> allChildrens = this -> getAllChildsFromAllNamesAndSymbols(allNameAndSymbols);
	return new CoffeeMachine(coffeeMachineName, allChildrens);
}

string CoffeeMachineTreeMaker :: getNameOfCoffeeMachineFromAllNamesAndSymbols(vector<string> allNameAndSymbols)
{
	try{
		if(allNameAndSymbols.size() < COFFEE_MACHINE_POS + 1)
			throw new BadException(COFFEE_MACHINE_NAME_ERR);
	}
	catch (BadException ex){
		ex.printMsg();
		return COFFEE_MACHINE_NOT_FOUND_RETURN;
	}
	return allNameAndSymbols[COFFEE_MACHINE_POS];
}

vector<Node*> CoffeeMachineTreeMaker :: getAllChildsFromAllNamesAndSymbols(vector<string> allNameAndSymbols)
{
	vector<Node*> allChilds;
	string commandSymbol = this -> getSymbolFromAllNamesAndSymbols(allNameAndSymbols);
	if(commandSymbol == INDEPENDENT_SYMBOL)
		allChilds = this -> getIndependentChildsFromAllNameAndSymbols(allNameAndSymbols);
	else if(commandSymbol == ALTERNATIVE_SYMBOL)
		allChilds = this -> getAlternativeChildsFromAllNameAndSymbols(allNameAndSymbols);
	else if(commandSymbol == OR_SYMBOL)
		allChilds = this -> getOrChildsFromAllNameAndSymbols(allNameAndSymbols);
	return allChilds;
}
string CoffeeMachineTreeMaker :: getSymbolFromAllNamesAndSymbols(vector<string> allNameAndSymbols)
{
	try{
		if(allNameAndSymbols.size() < SYMBOL_POS + 1)
			throw new BadException(SYMBOL_NOT_FOUND_ERR);
	}
	catch (BadException ex){
		ex.printMsg();
		return SYMBOL_NOT_FOUND_RETURN;
	}
	return allNameAndSymbols[SYMBOL_POS];
}

vector<Node*> CoffeeMachineTreeMaker :: getIndependentChildsFromAllNameAndSymbols(vector<string> allNameAndSymbols)
{
	vector <Node*> allChilds;
	for(int i = FIRST_NAME_POS ; i < allNameAndSymbols.size() ; i += 2)
	{
		if(this-> doesItOptional(allNameAndSymbols[i]))
			allChilds.push_back(this -> makeNewOptionalByName(allNameAndSymbols[i]));
		else
			allChilds.push_back(this -> makeNewMandatoryByName(allNameAndSymbols[i]));
	}
	return allChilds;
}

bool CoffeeMachineTreeMaker :: doesItOptional(string name)
{
	return name[0] == OPTIONAL_SYMBOL;
}

Optional* CoffeeMachineTreeMaker :: makeNewOptionalByName(string nameWithOptionalSymbol)
{
	string nameWithoutOptionalSymbol = nameWithOptionalSymbol.substr(1);
	return new Optional(nameWithoutOptionalSymbol);
}

Mandatory* CoffeeMachineTreeMaker :: makeNewMandatoryByName(string name)
{
	return new Mandatory(name);
}

vector<Node*> CoffeeMachineTreeMaker :: getAlternativeChildsFromAllNameAndSymbols(vector<string> allNameAndSymbols)
{
	vector <Node*> allChilds;
	for(int i = FIRST_NAME_POS ; i < allNameAndSymbols.size() ; i += 2)
	{
		allChilds.push_back(this -> makeNewAlternativeByName(allNameAndSymbols[i]));
	}
	return allChilds;
}

Alternative* CoffeeMachineTreeMaker :: makeNewAlternativeByName(string name)
{
	return new Alternative(name);
}

vector<Node*> CoffeeMachineTreeMaker :: getOrChildsFromAllNameAndSymbols(vector<string> allNameAndSymbols)
{
	vector <Node*> allChilds;
	for(int i = FIRST_NAME_POS ; i < allNameAndSymbols.size() ; i += 2)
	{
		allChilds.push_back(this -> makeNewOrByName(allNameAndSymbols[i]));
	}
	return allChilds;
}

Or* CoffeeMachineTreeMaker :: makeNewOrByName(string name)
{
	return new Or(name);
}

void CoffeeMachineTreeMaker :: addNewFeaturesToTree(vector<string> allNameAndSymbols, CoffeeMachine* ourCoffeeMachine)
{
	string featureName = this -> getNameOfFeatureFromAllNamesAndSymbols(allNameAndSymbols);
	try{
		Node* currentFeature = ourCoffeeMachine -> findChildByName(featureName);
		if(!currentFeature)
			throw BadException(FEATURE_NOT_FOUND_ERR);
		vector<Node*> childrensFromCommandLine = this -> getAllChildsFromAllNamesAndSymbols(allNameAndSymbols);
		currentFeature -> addNewChildrens(childrensFromCommandLine);
	}
	catch(BadException ex)
	{
		ex.printMsg();
	}
}

string CoffeeMachineTreeMaker :: getNameOfFeatureFromAllNamesAndSymbols(vector<string> allNameAndSymbols)
{
	try{
		if(allNameAndSymbols.size() < FEATURE_POS + 1)
			throw new BadException(FEATURE_NAME_ERR);
	}
	catch (BadException ex){
		ex.printMsg();
		return FEATURE_NOT_FOUND_RETURN;
	}
	return allNameAndSymbols[FEATURE_POS];
}