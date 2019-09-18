#pragma once
class CTest1
{
public:
	CTest1();
	virtual ~CTest1();

public:
	void ConstTest1(const int number)
	{
		//number = 100; // 에러 매개변수에 const가 있으므로
		m_nTestNumber = 20; 
	}
	void ConstTest2(int number) const
	{
		number = 100;
		//m_nTestNumber = 20; // 에러 함수선언 뒤에 const가 붙었으므로
		//int test = ConstTest3(20);
		//test = 200;
	}
	const int GetNumber()
	{
		return m_nTestNumber;
	}
	
public:
	// 순수 가상함수 상속시 구현해줘야한다.
	virtual void ChildTest() = 0;
	virtual void ChildTest2()
	{
		m_nTestNumber = 200;
	}

protected:
	int m_nTestNumber;

};

class CTestChild : public CTest1
{
public:	
	CTestChild();
	virtual ~CTestChild();
	
public:
	virtual void ChildTest()
	{
		m_nTestNumber = 20;
	}
};