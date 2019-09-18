// Study1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <string>
#include <crtdbg.h>
#include <vector>
#include <list>
#include <array>
#include <map>
#include <iostream>
#include <memory>
#include "CObject.h"
#include "Algorithm.h"
#include "Link.h"

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

class CTest
{
private:
	int num;
	string name;

public:
	decltype(num) GetNumber() {
		return num;
	}
	string GetName() {
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

	void Num2X()
	{
		auto fp = [this]() -> int { return num * 2; };
		cout << fp() << endl;
	}

	
};



void func(CTest test)
{
	string str = test.GetName();
	cout << str << " :: " << test.GetNumber() << endl;
}


void NewFor()
{
	vector<int> vecTest{ 0,1,2,3,4,5 };
	for (auto i : vecTest)
	{
		//cout << i << endl;
		i += 1;
	}

	map<int, int> mapTest{ { 0,10 },{ 1,11 },{ 2,22 },{ 3,33 } };
	for (auto i : mapTest)
	{
		cout << i.first << " :: " << i.second << endl;
	}

	vector<CTest> vecCTest{ { 0,"a" },{ 1,"b" },{ 2,"c" } };
	for (auto i : vecCTest)
	{
		cout << i.GetName() << i.GetNumber() << endl;
	}


	CTest test[] = { { 0,"a" },{ 1,"b" },{ 2,"c" } };
}

void ForwardTest(const CTest& test)
{
	cout << "Call const CTest&" << endl;
}

void ForwardTest(CTest&& test)
{
	cout << "Call CTest&&" << endl;
}


void LvalueRvalue()
{
	int a = 10;
	//int &b = 10; // error l-value 여야 한다.
	//int &&c = a; // error r-value 여야 한다.
	int &b = a;		
	int &&c = 10; // c가 l-value가 된다.
	int &d = c; // 가능
	int &&e = std::move(a); // a를 r-value로 바꿈
	int &&f = std::forward<int>(a); // a를 r-value로 바꿈

	CTest test;
	CTest& test1 = test;

	ForwardTest(test);						 // Call const CTest&
	ForwardTest(std::forward<CTest>(test));  // Call Ctest&&
	ForwardTest(std::move(test));			 // Call Ctest&&
	//CTest&& test2 = test; // error r-value가 아님​
	//CTest&& test2 = test; // error r-value가 아님​
	//CTest&& test2 = test; // error r-value가 아님​
	//CTest&& test2 = test; // error r-value가 아님​
}

void NewArrayTest()
{
	std::array<int, 5> arr = { 1 };
	arr.fill(3);
	for (auto i : arr)
	{
		cout << i << endl;
	}
}

// int AddFunc(int a, int b);
typedef int(*AddFunc) (int, int);
int CallAdd(AddFunc func, int a, int b)
{
	return func(a, b);
}

int Add(int a, int b)
{
	return a + b;
}

void LamdaTest()
{
	int a = CallAdd(Add, 20, 20);
	// [캡쳐] (매개변수1, 매개변수2...) 반환타입 {내부구현}
	int b = CallAdd([](int a, int b) -> int 
	{ 
		return a + b; 
	}, 10, 20);

	auto fp = []() -> int { return 100; };
	int c = fp();

	auto fp2 = [a, b, c]() -> int { return a+b+c; };
	int d = fp2();

	auto fp3 = [a, b, c]() -> void { cout << a << b << c << endl; };
	fp3();

	CTest test = CTest(100, "ff");
	test.Num2X();
}

void NewPtr()
{
	unique_ptr<int> p1(new int(4));	
	unique_ptr<int> p2 = move(p1); // p1은 empty 메모리가 p2에 이동

	shared_ptr<int> p3(new int(4));
	shared_ptr<int> p4 = p3; // p3 메모리가 p4에 복사됨
	*p4 = 5;

	shared_ptr<int> p5(new int(4));
	weak_ptr<int> p6 = p5; // p5 메모리가 p6에 새로 생성되어 복사됨
	p6.reset(); // p6만 empty

}

void LinkedList()
{
	CLink link;
	for (int i = 0; i < 10; i++)
	{
		link.PushBack(i);
	}

	for (int i = 0; i < 10; i++)
	{
		if (i % 3 == 0)
			link.Remove(i);
	}
	CNode *pCur = link.GetFirst();
	while (pCur != nullptr)
	{
		cout << pCur->GetValue() << endl;
		pCur = pCur->GetNext();
	}
	link.Clear();
}

int main()
{

	
	//LvalueRvalue();
	//NewArrayTest();
	//LamdaTest();
	//NewPtr();
 	CAlgorithm algo;
 	algo.Dojang3();
	
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
