#include "../include/Mandatory.h"
using namespace std;

Mandatory :: Mandatory(string _name) : Independent(_name)
{

}
bool Mandatory :: shouldBeExists(std::vector<string> membersOfConfiguration, Node* parent)
{
	return true;
}