#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));

	int n;
	n = rand() % 8000 + 100 ;
	cout << n << endl; 
	string stringToMake = "";
	for(int j = 0 ; j < n ; j++)
	{
		int len = rand() % 480 + 7;
		for (int i = 0 ; i < len ; i ++)
		{	
			int x =  (rand() % 26 + 97);
			char c = (char) (x);
			stringToMake += c;
		}
		cout << stringToMake <<endl;
		stringToMake = "";
	}
	
}