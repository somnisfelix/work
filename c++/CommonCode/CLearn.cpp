#include <string>
#include <crtdbg.h>
#include <vector>
#include <list>
#include <array>
#include <map>
#include <iostream>
#include <memory>
#include "CLearn.h"



CCLearn::CCLearn()
{
}


CCLearn::~CCLearn()
{
}


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

int AddInt(int a, int b)
{
	return a + b;
}

void LamdaTest()
{
	int a = CallAdd(AddInt, 20, 20);
	// [캡쳐] (매개변수1, 매개변수2...) 반환타입 {내부구현}
	int b = CallAdd([](int a, int b) -> int
	{
		return a + b;
	}, 10, 20);

	auto fp = []() -> int { return 100; };
	int c = fp();

	auto fp2 = [a, b, c]() -> int { return a + b + c; };
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

// 기본 템플릿
template<class T>
T Add(T a, T b)
{
	return a + b;
}

// 템플릿 특수화 오버로딩과 비슷함
template<> 
float Add(float a, float b)
{
	cout << "템플릿 특수화!!" << endl;
	return a * b;
}

// 템플릿 부분 특수화 오버로딩과 비슷함
template<typename T>
T Add(T a, string b)
{
	cout << "템플릿 부분 특수화!! : " << b << endl;
	return a ;
}

	

void CCLearn::Main()
{
	//LamdaTest();

	CTemplate<int> temp = CTemplate<int>(10, 20);
	int n = temp.Add();

	int add = Add<int>(20, 30);
	float add2 = Add<float>(10.0f, 20.0f);
	int add3 = Add<int>(20,"tt");
	
}

template<typename T>
T CTemplate<T>::Add() const
{
	return a + b;
}