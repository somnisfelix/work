#pragma once
class CPerson
{
public:
	CPerson();
	~CPerson();

	enum EMSex
	{
		MALE,
		FEMALE,
	};

	
protected:
	EMSex	m_emSex;
	int		m_age;

};

