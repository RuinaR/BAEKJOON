#include<iostream>
#include<vector>
using namespace std;

int main() {
	int count;
	cin >> count;
	vector<int>arr(count);
	vector<int>result(count);
	vector<int>num;

	int numSize = 0;
	for (int i = 0; i < count; i++)
	{
		cin >> arr[i];
		numSize = max(numSize, arr[i]);
	}
	num.resize(numSize + 1);
	for (int i = 0; i < count; i++)
		num[arr[i]]++;

	for (int i = 0; i < count; i++)
	{
		for (int j = 1; j * j <= arr[i]; j++)
		{
			if (!(arr[i] % j))
			{
				result[i] += num[j];
				if (arr[i] > j * j)
					result[i] += num[arr[i] / j];
			}
		}
	}
	for (int i = 0; i < count; i++)
		cout << result[i] - 1 << "\n";
	return 0;
}