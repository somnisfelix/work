#include "pch.h"
#include <string>
#include "CObject.h"


CObject::CObject() : m_hp(0), m_atk(0)
{
}

CObject::~CObject()
{
	printf("%s CObject ���� \n", GetName());
}

CPCLiveObject::~CPCLiveObject()
{
	printf("%s CPCLiveObject ���� \n", GetName());
}

CNonLiveObject::~CNonLiveObject()
{
	printf("%s CNonLiveObject ���� \n", GetName());
}

CLiveObject::~CLiveObject()
{
	printf("%s CLiveObject ���� \n", GetName());
}


void CPCLiveObject::RunAction(CObject &object)
{
	if (object.GetType() == EMType::NONLIVE_OBJECT)
	{
		CNonLiveObject *pNonLiveObject = dynamic_cast<CNonLiveObject *>(&object);
		switch (pNonLiveObject->GetNonLiveType())
		{
		case CNonLiveObject::EMNonLiveType::ITEM:
			m_atk += pNonLiveObject->GetAtk();
			m_hp += pNonLiveObject->GetHP();

			printf("%s�� %s�� ���� atk�� +%d hp�� %d \n", GetName().c_str(), pNonLiveObject->GetName().c_str(), pNonLiveObject->GetAtk(), pNonLiveObject->GetHP());
			break;
		case CNonLiveObject::EMNonLiveType::TRAP:
			m_hp -= pNonLiveObject->GetAtk();
			break;
		}
		pNonLiveObject->SetDead();
	}
	else {
		CLiveObject *pLiveObject = dynamic_cast<CLiveObject *>(&object);
		switch (pLiveObject->GetLiveType())
		{
		case CPCLiveObject::EMLiveType::MONSTER:
			int dmg = pLiveObject->GetAtk() - m_def;
			dmg = dmg > 0 ? dmg : 0;
			SetDamage(dmg);


			printf("%s�� %s����  hp�� -%d hp : %d \n", pLiveObject->GetName().c_str(), GetName().c_str(), dmg, GetHP());

			dmg = m_atk - pLiveObject->GetDef();
			dmg = dmg > 0 ? dmg : 0;
			pLiveObject->SetDamage(dmg);

			printf("%s�� %s����  hp�� -%d hp : %d \n", GetName().c_str(), pLiveObject->GetName().c_str(), dmg, pLiveObject->GetHP());

			break;
		}
	}
}
