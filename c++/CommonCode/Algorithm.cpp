
#include <string>
#include <iostream>
#include <math.h>
#include "Algorithm.h"
using namespace std;

void CAlgorithm::Dojang1()
{
	int sum = 0;
	for (int i = 1; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}
	cout << sum << endl;
}


int CAlgorithm::GetGenerator(int number)
{
	int sum = number;
	while (number != 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

#define MAX_NUMBER 5000
void CAlgorithm::Dojang2()
{
	bool result[MAX_NUMBER] = { false };
	for (int i = 1; i < MAX_NUMBER; i++)
	{
		int generator = GetGenerator(i);
		if (generator < MAX_NUMBER)
		{
			result[generator] = true;
		}
		else {
			break;
		}
	}
	int sum = 0;
	for (int i = 0; i < MAX_NUMBER; i++)
	{
		if (result[i] == false)
		{
			sum += i;
		}
	}
	cout << "sum : " << sum << endl;
}

int CAlgorithm::PowCount(int num)
{
	cout << num << " : ";

	int count = 0;
	while (true)
	{
		float fSqrt = sqrtf((float)num);
		float fTemp = (int)fSqrt;
		if (fSqrt - fTemp != 0.0f || num == fSqrt)
		{

			cout << num << "(" << count << ")" << endl;
			break;
		}
		count++;

		num = fSqrt;
	}


	return 0;
}

void CAlgorithm::Dojang3()
{
	PowCount(1);
	PowCount(15);
	PowCount(16);
	PowCount(49);
	PowCount(64);
	PowCount(100);
	PowCount(256);
}