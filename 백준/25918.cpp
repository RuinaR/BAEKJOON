#include <stack>
#include <iostream>
using namespace std;
int main(void)
{
	stack<char> st;
	int N = 0;
	string S;

	cin >> N;
	cin >> S;

	int d = 0;
	int maxD = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (st.empty() || st.top() == S[i])
		{
			st.push(S[i]);
			d++;
		}
		else
		{
			st.pop();
			maxD = max(maxD, d);
			d--;
		}
	}

	if (!st.empty())
		cout << -1;
	else
		cout << maxD;

	return 0;
}