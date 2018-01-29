#include "../include/BadException.h"

using namespace std;

BadException :: BadException(string msg)
{
	massage = msg;
}
void BadException:: printMsg()
{
	cout << massage << endl;
}