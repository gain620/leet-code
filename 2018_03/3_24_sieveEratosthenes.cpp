#include <iostream>

using namespace std;

int main()
{
	bool checkArr[1000] = { false };
	int primeArr[1000];
	int cnt = 0;

	for (int i = 2; i < 1000; ++i)
	{
		if (!checkArr[i])
		{
			primeArr[cnt++] = i;

			for (int j = 2*i; j < 1000; j+=i)
			{
				checkArr[j] = true;
			}
		}
		
	}

	for (int i = 0; i<cnt; i++)
	{
		cout << primeArr[i] << ", ";
	}


	return 0;
}