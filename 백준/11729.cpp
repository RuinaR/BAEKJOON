#include <iostream>
#include <math.h>
using namespace std;

void Hanoi(int start, int mid, int end, int n)
{
	if (n <= 0)
		return;

	Hanoi(start, end, mid, n - 1);
	cout << start << " " << end << '\n';
	Hanoi(mid, start, end, n - 1);
}

int main(void)
{
	int input = 0;
	cin >> input;

	cout << (long long)pow(2, input) - 1 << '\n';
	Hanoi(1, 2, 3, input);

	return 0;
}