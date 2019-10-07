
#include <string>
#include <iostream>
#include <math.h>
#include <vector>
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


int CAlgorithm::GetTargetNumCount(int number, int targetNum)
{
	int cnt = 0;
	while (number != 0)
	{
		if ((number % 10) == targetNum)	
			cnt++;
		number /= 10;
	}
	return cnt;
}

void CAlgorithm::Dojang4()
{
	int totalCnt = 0;
	for (int i = 1; i < 10000; i++)
	{
		totalCnt += GetTargetNumCount(i, 8);
	}
	cout << totalCnt << endl;
}

float CAlgorithm::GetDiagonal(float fBase, float fHeight)
{
	return sqrtf(powf(fBase,2) + powf(fHeight,2));
}

void CAlgorithm::Dojang5()
{
	GetDiagonal(3, 4);
}

void CAlgorithm::PrintSpiralArray1(int XSize, int YSize)
{
	int *pSpiralArray = new int[XSize*YSize];
	// Make Double Array
	memset(pSpiralArray, 0, sizeof(int) * XSize*YSize);

	int addDir = 0, start = 0, endX = XSize - 1, endY = YSize - 1, x = 0, y = 0, num = 0;
	// 0 : 오른쪽
	// 1 : 아래
	// 2 : 위
	// 3 : 왼쪽
	while (true)
	{
		switch (addDir)
		{
		case 0:
			if (start == endX)
			{
				pSpiralArray[(x)+(y * XSize)] = num;
				x++;
				num++;
			}
			else {
				for (int i = start; i < endX; i++)
				{
					pSpiralArray[(x)+(y * XSize)] = num;
					x++;
					num++;
				}
			}
			addDir = 1;
			break;
		case 1:
			if (start == endY)
			{
				pSpiralArray[(x)+(y * XSize)] = num;
				y++;
				num++;
			}
			else
			for (int i = start; i < endY; i++)
			{
				pSpiralArray[(x)+(y * XSize)] = num;
				y++;
				num++;
			}
			addDir = 2;
			break;
		case 2:
			for (int i = start; i < endX; i++)
			{
				pSpiralArray[(x)+(y * XSize)] = num;
				x--;
				num++;
			}
			addDir = 3;
			break;
		case 3:
			for (int i = start; i < endY; i++)
			{
				pSpiralArray[(x)+(y * XSize)] = num;
				y--;
				num++;
			}
			addDir = 0;
			start++;
			x++;
			y++;
			endX--;
			endY--;
			break;
		}

		//if (addDir == 4) break;
		if (num >= XSize*YSize)break;
	}

	for (int j = 0; j < YSize; j++)
	{
		for (int i = 0; i < XSize; i++)
		{
			printf("%02d ", pSpiralArray[i + (j * XSize)]);
		}
		cout << endl;
	}
	
	delete[] pSpiralArray;
}



void CAlgorithm::PrintSpiralArray2(int XSize, int YSize)
{
	int *pSpiralArray = new int[XSize*YSize];
	// Make Double Array
	memset(pSpiralArray, 0, sizeof(int) * XSize*YSize);

	int addDir = 0, index = -1, delta = 0, limit = 0, num = 0, curSize;
	// 0 : 오른쪽
	// 1 : 아래
	// 2 : 위
	// 3 : 왼쪽
	while (true)
	{
		switch (addDir)
		{
		case 0:			
			delta = 1;
			curSize = XSize - limit;
			break;
		case 1:
			delta = XSize;
			curSize = YSize - limit;
			break;
		case 2:
			delta = -1;
			curSize = XSize - limit;
			break;
		case 3:
			delta = -XSize;
			curSize = YSize - limit;
			break;
		}

		for (int i = 0; i < curSize; i++)
		{
			index += delta;
			pSpiralArray[index] = num;
			num++;
		}

		if (num >= XSize*YSize)break;

		switch (addDir)
		{
		case 0:
			limit++;
			addDir = 1;
			break;
		case 1:
			addDir = 2;
			break;
		case 2:
			limit++;
			addDir = 3;
			break;
		case 3:
			addDir = 0;
			break;
		}
	}

	for (int j = 0; j < YSize; j++)
	{
		for (int i = 0; i < XSize; i++)
		{
			printf("%02d ", pSpiralArray[i + (j * XSize)]);
		}
		cout << endl;
	}

	delete[] pSpiralArray;
}

void CAlgorithm::Dojang6()
{
	PrintSpiralArray2(3, 3);
}

void CAlgorithm::StringCompress(string s)
{
	int minLength = s.length();
	int halfSize = s.length() / 2;	
	string strShortChar;
	
	for (int i = 1; i <= halfSize; i++)
	{
		
		int sameCnt = 1;
		int length = 0;
		string targetChar = s.substr(0, i);
 		string strNewChar;
		int j = i;
		for (; j < s.length(); j += i)
		{
			string curChar = s.substr(j, i);
			if (targetChar == curChar)
			{
				sameCnt++;
			}
			if(targetChar != curChar )
			{
				if (sameCnt == 1)
				{
					length += i;
				}
				else {
					length += i + 1;
				}
				if (sameCnt != 1)
					strNewChar.append(to_string(sameCnt));
				strNewChar.append(targetChar);
				targetChar.clear();
				targetChar = curChar;
				sameCnt = 1;
			}
		}
		if (sameCnt == 1)
		{
			length += targetChar.length();
		}
		else {
			length += targetChar.length() + 1;
		}
		if (sameCnt != 1)
			strNewChar.append(to_string(sameCnt));
		strNewChar.append(targetChar);
		targetChar.clear();

		if (minLength >= length)
		{
			minLength = length;
			strShortChar = strNewChar;
		}
	}
	cout << strShortChar << " length : " << minLength << endl;
	
}

void CAlgorithm::Dojang3N_1(int param1, int param2)
{
	int maxCnt = 0;
	
	for (int i = param1; i <= param2; i++)
	{
		int num = i;

		int cnt = 1;
		while (num != 1)
		{
			if (num % 2 == 0)
			{
				num /= 2;
			}
			else {
				num = num * 3;
				num++;
			}
			cnt++;
		}
		if (cnt > maxCnt)
			maxCnt = cnt;
	}

	cout << param1 << " " << param2 << " " << maxCnt << endl;
}

bool CAlgorithm::IsSameNumber(int num)
{
	string str = to_string(num);
	int length = str.length();
	int half = str.length() / 2;
	for (int i = 0; i < half; i++)
	{
		if (str[i] != str[(length - 1) - i])
			return false;
	}
	
	return true;
}

void CAlgorithm::SameNumber(int cnt)
{
	int num = -1;
	int curCnt = 0;
	while (curCnt < cnt)
	{
		num++;
		if (IsSameNumber(num))
		{
			curCnt++;
		}

	}
	cout << cnt << " " << num << endl;
}

bool CAlgorithm::IsUglyNumber(int num)
{
	if (num % 2 == 0)
	{
		if (num > 2)
		{
			if (IsUglyNumber(num / 2) == false) return false;
		}
	}else if (num % 3 == 0)
	{
		if (num > 3)
		{
			if (IsUglyNumber(num / 3) == false) return false;
		}
	}else if (num % 5 == 0)
	{
		if (num > 5)
		{
			if (IsUglyNumber(num / 5) == false) return false;
		}
	}
	else {
		return false;
	}
	return true;
}

void CAlgorithm::UglyNumbers(int cnt)
{
	int index = 1;
	int number = 1;
	while (index != cnt)
	{
		number++;
		if(IsUglyNumber(number))
		{
			index++;
		}
	}
	cout << index << " " << number << endl;
}

void CAlgorithm::Main()
{
	/*StringCompress("aabbaccc");
	StringCompress("ababcdcdababcdcd");
	StringCompress("abcabcdede");
	StringCompress("abcabcabcabcdededededede");
	StringCompress("xababcdcdababcdcd");*/


	//IsSameNumber(202);

	UglyNumbers(1550);

}

