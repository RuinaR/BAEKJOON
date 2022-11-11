#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main(void)
{
	int T = 0;
	int count = 0;
	string inputStr;
	string funcStr;
	bool isErr;
	bool isR;
	deque<string> resultDq;
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		isErr = false;
		isR = false;
		cin >> funcStr;
		cin >> count;
		cin >> inputStr;

		deque<int> dq;
		int data = 0;
		bool lastNum = false;
		for (int i = 0; i < inputStr.size(); i++)
		{
			if (inputStr[i] >= '0' && inputStr[i] <= '9')
			{
				if (lastNum)
					data *= 10;
				data += inputStr[i] - '0';
				lastNum = true;
			}
			else
			{
				if (lastNum)
				{
					dq.push_back(data);
					data = 0;
				}
				lastNum = false;
			}
		}

		for (int i = 0; i < funcStr.size(); i++)
		{
			if (funcStr[i] == 'R')
				isR = !isR;

			if (funcStr[i] == 'D')
			{
				if (dq.empty())
				{
					isErr = true;
					break;
				}
				else if (isR)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}

		if (isErr)
		{
			resultDq.push_back("error\n");
		}
		else
		{
			string result;
			if (isR)
			{
				result = "[";
				if (!dq.empty())
				{
					result += to_string(dq.back());
					dq.pop_back();

					while (!dq.empty())
					{
						result += ',';
						result += to_string(dq.back());
						dq.pop_back();
					}
				}
				result += "]\n";
			}
			else
			{
				result = "[";
				if (!dq.empty())
				{
					result += to_string(dq.front());
					dq.pop_front();
					while (!dq.empty())
					{
						result += ',';
						result += to_string(dq.front());
						dq.pop_front();
					}
				}
				result += "]\n";
			}
			resultDq.push_back(result);
			result = "";
		}
	}

	while (!resultDq.empty())
	{
		cout << resultDq.front();
		resultDq.pop_front();
	}

	return 0;
}