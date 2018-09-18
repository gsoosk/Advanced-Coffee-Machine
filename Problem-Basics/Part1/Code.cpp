#include <iostream>
#include <string>
using namespace std;

string makeBeautifulString(string stringToMake)
{
	string beautifullString = "";

	for (int i = 0 ; i < stringToMake.length() ; i++)
	{
		if (stringToMake[i] == 'a' || stringToMake[i] == 'b' || stringToMake[i] == 'c')
			beautifullString += stringToMake[i];
	}

	return beautifullString;
}

int main() 
{
	int n;
	cin >> n;

	for (int i = 0 ; i < n ; i++)
	{
		string stringToCheck;
		cin >> stringToCheck;

		string beautifullString;
		beautifullString = makeBeautifulString(stringToCheck);

		if(beautifullString != "")
			cout << beautifullString << endl;
	}

	return 0;
}