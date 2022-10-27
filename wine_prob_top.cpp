#include <iostream>
using namespace std;

int wineSolver(int arr[], int i, int j, int y, int **dp)
{
	//base case
	if (i > j)
	{
		return 0;
	}

	//dp case
	if (dp[i][j] != 0)
	{
		return dp[i][j];
	}

	//recursive call
	int ops1 = arr[i] * y + wineSolver(arr, i + 1, j, y + 1, dp);
	int ops2 = arr[j] * y + wineSolver(arr, i, j - 1, y + 1, dp);

	return dp[i][j] = max(ops1, ops2);
}

int main()
{
	int n;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int **dp = new int*[n];

	for (int i = 0; i < n; i++)
	{
		dp[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = 0;
		}
	}

	cout << wineSolver(arr, 0, n - 1, 1, dp);

	delete[] dp;

	return 0;
}