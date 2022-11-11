#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	string strN;
	string strM;
	cin >> strN;
	cin >> strM;

	int N = stoi(strN);
	int M = stoi(strM);;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;
		v.push_back(data);
	}
	int start = 0;
	int end = 0;
	int maxValue = 0;
	int sum = 0;

	while (end < N)
	{
		if (sum <= M)
		{
			if (sum + v[end] == M || sum == M)
			{
				maxValue = M;
				break;
			}
			else if (sum + v[end] < M)
			{
				sum += v[end];
				maxValue = max(maxValue, sum);
				end++;
			}
			else
			{
				sum += v[end];
				sum -= v[start];
				if (sum <= M)
					maxValue = max(maxValue, sum);
				end++;
				start++;
			}
		}
		else
		{
			if (start < end)
			{
				sum -= v[start];
				if (sum <= M)
					maxValue = max(maxValue, sum);
				start++;
			}
			else if (start == end)
			{
				sum += v[end];
				sum -= v[start];
				if (sum <= M)
					maxValue = max(maxValue, sum);
				start++;
				end++;
			}
		}
	}

	cout << maxValue << '\n';

	return 0;
}