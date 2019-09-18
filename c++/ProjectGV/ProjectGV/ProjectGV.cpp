// ProjectGV.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <crtdbg.h>

using namespace std;


class CTest
{
private:
	int num;
	string name;

public: 
	decltype(num) GetNumber() {
		return num;
	}
	string GetName()	{
		return name;
	}
	CTest(int _num, const string &_name)
		: num(_num)
		, name(_name)
	{
	}
	CTest()
	{
	}
};



void func(CTest test)

{

	cout << test.GetNumber() << " :: " << test.GetName() << endl;

}

auto AddNum(int a, int b) -> int
{
	return a + b;
}


CTest returnTest()
{
	return CTest();
}

int main()
{
	/*char *pChar;
	int *pInteger;
	short *pShort;

	pChar = (char *)0x0000;
	pInteger = (int *)0x0000;
	pShort = (short *)0x0000;

	printf("pChar = %x, pShort = %x, pInteger = %x\n", pChar, pShort, pInteger);

	pChar += 1;
	pInteger += 1;
	pShort += 1;

	printf("pChar = %x, pShort = %x, pInteger = %x\n", pChar, pShort, pInteger);*/
	{
		vector<int> vecTest{ 0,1,2,3,4,5 };
		for (auto i : vecTest)
		{
			cout << i << endl;
		}

		map<int, int> mapTest{ {0,10}, {1,11},{ 2,22 },{ 3,33 } };
		for (auto i : mapTest)
		{
			cout << i.first << " :: " << i.second << endl;
		}

		vector<CTest> vecCTest{ {0,"a"},{ 1,"b" },{ 2,"c" } };
		for (auto i : vecCTest)
		{
			cout << i.GetName() << i.GetNumber() << endl;
		}


		CTest test[] = { { 0,"a" },{ 1,"b" },{ 2,"c" } };

		decltype(test[0].GetName()) str = "tt";

		int add = AddNum(2, 3);
	}

	{
		int a = 10;
		//int &b = 10; // error l-value 여야 한다.
		//int &&c = a; // error r-value 여야 한다.
		int &&c = std::move(a); 
		CTest test ;
		CTest& test1 = test; 
		//CTest&& test2 = test; // error r-value가 아님
	}

	/*bool bTest[20] = { false };
	for (int i : bTest)
	{
		cout << bTest[i] << endl;
	}*/

    return 0;
}

