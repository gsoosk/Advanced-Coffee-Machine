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
		int len = rand() % 48 + 1;
		for (int i = 0 ; i < len ; i ++)
		{	
			int x =  (rand() % 3);
			if(x == 0)
				stringToMake += 'a';
			else if(x == 1)
				stringToMake += 'b';
			else if(x == 2)
				stringToMake += 'c';
		}
		cout << stringToMake <<endl;
		stringToMake = "";
	}
	
}