#include<iostream>
using namespace std;
int main()
{
    int n ;
    cin >> n;
	int column = n * 2;
	int row = n;
	for( int i = 0 ; i < row ; ++i )
	{
		for( int j = 0; j < column; ++j )
		{
			if( j == ((column/2) - i))
				for( int k = 0 ; k < (2*i) ; ++k )
				{
					cout << ' ';
					++j;
				}
            
            if ( i % 3 == 0)
			    cout << 'a';
            else if ( i % 3 == 1)
                cout << 'b';
            else if ( i % 3 == 2)
                cout << 'c';

		}
		cout << endl;
	}
	return 0;
}