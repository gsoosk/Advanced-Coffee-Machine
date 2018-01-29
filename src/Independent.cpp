#include "../include/Independent.h"
using namespace std;

Independent :: Independent(string _name) : Feature(_name)
{

}

bool Independent :: doesItDependent()
{
	return false;
}
