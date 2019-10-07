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

void CCLearn::ConstCast()
{
	const int *pConstNum = new int(10);
	// 에러!!
	// int *pInt = pConstNum;
	int *pInt = const_cast<int*>(pConstNum);
	*pInt = 200;

	delete pConstNum;
}

void CCLearn::DynamicCast()
{
	class A
	{
	public:
		virtual void AAA() {
			cout << "AAA" << endl;
		};
	};

	class B : public A
	{
	public:
		void AAA() {
			cout << "BBB" << endl;
		};
	};

	A *pA = new A();
	// pB2가 NULL임
	B *pB2 = dynamic_cast<B*>(pA);

	A *pAB = new B();
	B *pB3 = dynamic_cast<B*>(pAB);

	pA->AAA();
	pB3->AAA();

	delete pA;
	delete pAB;
}

void CCLearn::StaticCast()
{
	class A
	{
	public:
		virtual void AAA() {
			cout << "AAA" << endl;
		};
	};

	class B : public A
	{
	public:
		void AAA() {
			cout << "BBB" << endl;
		};
	};

	A *pA = new A();
	// pB2가 casting 됨
	B *pB2 = static_cast<B*>(pA);
	// 둘다 AAA가 출력
	pA->AAA();
	pB2->AAA();

	A *pAB = new B();
	B *pB3 = static_cast<B*>(pAB);
	// 둘다 BBB가 출력
	pAB->AAA();
	pB3->AAA();
	delete pA;
	delete pAB;

	int i = 0;
	float j = 30.0f;
	// 경고 발생
	//i = j;
	i = static_cast<int>(j);

	void *v = &i;
	// 캐스팅이 가능
	//int *k = static_cast<int *>(v);
	int *k = (int *)(v);
}

void CCLearn::AutoPtr()
{
	{
		// 메모리 사용후 자동으로 제거함
		std::auto_ptr<CTest> pTest(new CTest(20, "test"));
		// pTest는 null
		std::auto_ptr<CTest> pTest2 = pTest;
		// 메모리 해제 굳이 하지 않아도 됨
		pTest2.reset();
	}

	{
		// 포인터의 이동이 불가능하고 std::move함수를 통해 이동이 가능하다.
		// const를 붙이면 std::move를 통해서도 이동이 불가능하다.
		std::unique_ptr<CTest> pTest(new CTest(20, "test"));
		// 에러!!
		// std::unique_ptr<CTest> pTest2 = pTest;
		// pTest는 null
		std::unique_ptr<CTest> pTest2 = std::move(pTest);
		pTest2.reset();
	}

	{

		// 포인터의 공유가 가능하고 공유객체가 늘어날수록 레퍼런스 카운트가 증가한다.
		std::shared_ptr<CTest> pTest(new CTest(20, "test"));
		// use_count = 1;
		cout << pTest.use_count() << endl;
		// pTest가 null이 되지 않음
		std::shared_ptr<CTest> pTest2 = pTest;
		// use_count = 2;
		cout << pTest.use_count() << endl;
		// use_count = 1;
		pTest2.reset();
		// use_count = 0;
		pTest.reset();


		// 배열 생성이 가능하지만 .reset을 통해 delete[]가 호출되지 않는다.
		/*std::shared_ptr<CTest> pTest3(new CTest[20]);
		// 에러!!
		pTest3.reset();

		// 소멸할때 사용할 함수를 미리 정의하면 제대로 삭제됨
		std::shared_ptr<CTest> pTest3(new CTest[20], [](CTest *pTest)
		{
			delete[] pTest;
		});*/
	}
	// shared_ptr 레퍼런스 카운팅 방식의 잠재적인 위험 가운데 하나로 서로를 참조하는 순환참조 문제가 있다. 
	// A는 B를 가리키고, B는 다시 A를 가리키는 상황이 바로 순환참조 상황이다. 이런 상황에서는 순환참조에 
	// 참여하는 모든 인스턴스가 삭제될 수 없으며, 이는 곧장 메모리 누수로 이어진다. 
	// shared_ptr이 자신을 제외하고 하나라도 남아 있으면, 아무리 삭제 명령을 내려도 해당 메모리가 삭제되지 않지만 
	// 해당 메모리를 가리키는 포인터 타입이 shared_ptr이 아닌, weak_ptr 이라면 해당 메모리는 삭제될수 있다
	{
		std::shared_ptr<int> sp1(new int(5)); // create, ref = 1
		std::weak_ptr<int> wp1 = sp1;   // ref = 1
		{
			// sp1은 wp1으로 sp2를 복사
			std::shared_ptr<int> sp2 = wp1.lock();  // ref = 2

			if (sp2) {
				std::cout << "sp2 has copy of sp1" << std::endl; // 
			}
		} // sp2는 이곳에서 자동으로 파괴됨, ref = 1

		sp1.reset(); // sp1은 이곳에서 파괴됨, ref = 0, sp1은 null
	}
}

void CCLearn::Main()
{
	//LamdaTest();

	/*CTemplate<int> temp = CTemplate<int>(10, 20);
	int n = temp.Add();

	int add = Add<int>(20, 30);
	float add2 = Add<float>(10.0f, 20.0f);
	int add3 = Add<int>(20,"tt");*/
	//ConstCast();
	//DynamicCast();
	//StaticCast();
	AutoPtr();
	
}

template<typename T>
T CTemplate<T>::Add() const
{
	return a + b;
}