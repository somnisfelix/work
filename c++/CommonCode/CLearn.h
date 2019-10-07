#pragma once
using namespace std;

class CCLearn
{
public:
	CCLearn();
	~CCLearn();

	void Main();

private:
	void ConstCast();
	void DynamicCast();
	void StaticCast();
	void AutoPtr();
};

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


// 템플릿 클래스
template<typename T>
class CTemplate
{
private:
	T a;
	T b;
public:
	CTemplate(T _a, T _b)
		: a(_a), b(_b)
	{
	}
	T Add() const;
};


