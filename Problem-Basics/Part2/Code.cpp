#include <iostream>
#include <string>
using namespace std;

bool doestItSuperBeautifull(string stringToCheck)
{
	int numberOfA = 0;
	int numberOfB = 0;
	int numberOfC = 0;
	for (int i = 0 ; i < stringToCheck.length() ; i++)
	{
		switch(stringToCheck[i])
		{
			case('a'):
				numberOfA ++ ;
				break;
			case('b'):
				numberOfB ++;
				break;
			case('c'):
				numberOfC ++;
				break;
			default:
				break;
		}
	}
	return numberOfA == numberOfB && numberOfA == numberOfC ;
}

int main() 
{
	int n;
	cin >> n;
 
	float sum = 0;
	int numberOfSuperBeautifulls = 0;

	for (int i = 0 ; i < n ; i++)
	{
		string stringToCheck;
		cin >> stringToCheck;

		if ( doestItSuperBeautifull( stringToCheck ) )
		{
			sum += stringToCheck.length();
			numberOfSuperBeautifulls ++;
			cout << stringToCheck << endl;
		}
	}

	if(numberOfSuperBeautifulls == 0)
		cout << 0;
	else 
		cout << sum / numberOfSuperBeautifulls;
	return 0;
}