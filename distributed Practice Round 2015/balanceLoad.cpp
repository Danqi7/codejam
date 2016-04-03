#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
#include "load_balance.h"

using namespace std;

int main()
{
	int size = GetN();
	int total = 0;
	//get total
	for (int i = 0; i < size; i++)
	{
		total += GetWeight(i);
	}

	int target = total / 2;
	//cout << total;
	//cout << target;
	vector< vector<bool> > table(size+1, vector<bool>(target+1, true));

	//table[i][0] with sum = 0 and A[1..i]
	for (int i = 0; i < table.size(); i++)
		table[i][0] = true;
	//table[0][j] with sum != 0 and empty set of numbers
	for (int j = 1; j < table[0].size(); j++)
		table[0][j] = false;

	for (int i = 1; i < table.size(); i++)
	{
		for (int j = 1; j < table[0].size(); j++)
		{
			if (j-GetWeight(i-1) >= 0)
				table[i][j] = table[i-1][j] || table[i-1][j-GetWeight(i-1)];
			else
				table[i][j] = table[i-1][j];
		}
	}
	

	if (table[size][target] == true)
		cout << "POSSIBLE";
	else
		cout << "IMPOSSIBLE";

	cout << endl;

	return 0;
}