#include <iostream>
using namespace std;


#define CAPACITY 2188
char arr[CAPACITY][CAPACITY] = { 0 };
int dataSize = 0;

void SetArrData(int power)
{
	if (!power)
	{
		arr[0][0] = '*';
		return;
	}
	SetArrData(power - 1);

	int unit = 1;
	for (int i = 0; i < power - 1; i++)
	{
		unit *= 3;
	}

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			for (int i = 0; i < unit; i++)
			{
				for (int j = 0; j < unit; j++)
				{
					if (!(x == 1 && y == 1))
						arr[i + (unit * x)][j + (unit * y)] = arr[i][j];
				}
			}
		}
	}
}

void Star(int n)
{
	int power = 0;
	dataSize = n;
	while (n != 1)
	{
		n /= 3;
		power++;
	}

	SetArrData(power);
}

void printArr()
{
	for (int i = 0; i < dataSize; i++)
	{
		for (int j = 0; j < dataSize; j++)
		{
			if (arr[i][j])
			{
				cout << arr[i][j];
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
}

int main(void)
{
	int input = 0;
	cin >> input;
	Star(input);
	printArr();
	return 0;
}