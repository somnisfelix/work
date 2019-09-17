// Study1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <crtdbg.h>
#include <vector>
#include <list>
#include "CObject.h"
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

typedef vector<CObject *>::iterator Iter;

using namespace std;

void Test1()
{

	vector<CObject *> vecObjects;
	CLiveObject *pMonster1 = new CLiveObject("몬스터", 10, 13, 10);
	vecObjects.push_back(pMonster1);

	CNonLiveObject *pItem1 = new CNonLiveObject("포션1", CNonLiveObject::EMNonLiveType::ITEM, 20, 0);
	vecObjects.push_back(pItem1);

	CNonLiveObject *pItem2 = new CNonLiveObject("포션2", CNonLiveObject::EMNonLiveType::ITEM, 0, 10);
	vecObjects.push_back(pItem2);

	CLiveObject *pMonster2 = new CLiveObject("로보트", 20, 24, 12);
	vecObjects.push_back(pMonster2);


	CNonLiveObject *pItem3 = new CNonLiveObject("포션3", CNonLiveObject::EMNonLiveType::ITEM, 20, 0);
	vecObjects.push_back(pItem3);

	CLiveObject *pMonster3 = new CLiveObject("좀비", 30, 20, 8);
	vecObjects.push_back(pMonster3);

	CPCLiveObject *pPCObject = new CPCLiveObject("주인공", 200, 23, 12);
	Iter iter = vecObjects.begin();
	for (; iter != vecObjects.end();)
	{
		while (!(*iter)->IsDead())
		{
			pPCObject->RunAction(*(*iter));
		}
		delete *iter;
		iter = vecObjects.erase(iter);
	}
	delete pPCObject;
}

void Test2()
{
	CLiveObject *pMonster1 = new CLiveObject("몬스터", 10, 13, 10);
	delete pMonster1;


	CPCLiveObject *pPCObject = new CPCLiveObject("주인공", 200, 23, 12);
	delete pPCObject;
}

void Test3()
{
	int a = 40;
	int *p;
	p = &a;
	p[0] = 50;

	cout << "a  : " << a << " 주소 : " << &a << endl;
	cout << "p  : " << *p << " 주소 : " << p << endl;
}

void Dojang1()
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


int GetGenerator(int number)
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
void Dojang2()
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

void NewFor()
{
	int test[] = { 1,2,3,4 };
	decltype(test) test2 = { 1,2,3,4 };
	vector<int> vecTest = { 1,2,3,4,5 };
	//auto iter = vecTest.begin();
	for (auto i : vecTest)
	{
		cout << i << endl;
	}
}

class CTest
{
};

void LvalueRvalue()
{
	int a = 10;
	//int &b = 10; // error l-value 여야 한다.
	//int &&c = a; // error r-value 여야 한다.
	int &b = a;		
	int &&c = 10; // c가 l-value가 된다.
	int &d = c; // 가능
	int &&e = std::move(a); // a를 r-value로 바꿈

	CTest test;
	CTest& test1 = test;
	//CTest&& test2 = test; // error r-value가 아님​
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtDumpMemoryLeaks();
	

	
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
