#pragma once
class CTest1
{
public:
	CTest1();
	virtual ~CTest1();

public:
	void ConstTest1(const int number)
	{
		//number = 100; // ���� �Ű������� const�� �����Ƿ�
		m_nTestNumber = 20; 
	}
	void ConstTest2(int number) const
	{
		number = 100;
		//m_nTestNumber = 20; // ���� �Լ����� �ڿ� const�� �پ����Ƿ�
		//int test = ConstTest3(20);
		//test = 200;
	}
	const int GetNumber()
	{
		return m_nTestNumber;
	}
	
public:
	// ���� �����Լ� ��ӽ� ����������Ѵ�.
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