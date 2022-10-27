//Greedy Way for Indian Coin Change

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n = 10;
	int denom[n] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

	int val;
	cin >> val;
	int coins = 0;

	while (val > 0)
	{
		int up = upper_bound(denom, denom + n, val) - denom - 1;

		coins = coins + val / denom[up];
		val = val % denom[up];
	}

	cout << coins;
}