#pragma once
using namespace std;
class CObject
{
public:
	enum EMType
	{
		LIVE_OBJECT, // 살아있는 오브젝트 (몬스터, PC)
		NONLIVE_OBJECT, // 죽어있는 오브젝트 (아이템, 함정)
	};

	CObject();	
	virtual ~CObject();


protected:
	void CreateObject(const string strName, const EMType emType, const int hp, const int atk)
	{
		m_hp = hp;
		m_atk = atk;
		m_strName = strName;
		m_emType = emType;
	}

protected:
	EMType m_emType;
	string m_strName;
	int m_hp;	// 생명력
	int m_atk;	// 공격력

public:
	EMType GetType() const {
		return m_emType;
	}
	int GetHP() const { return m_hp; }
	int GetAtk() const { return m_atk; }
	void SetDamage(int dmg)
	{
		m_hp -= dmg;
		if (m_hp < 0) m_hp = 0;
	}
	bool IsDead() const { return m_hp <= 0; }
	void SetDead()
	{
		m_hp = 0;
	}
	string GetName() const { return m_strName; }

};

class CLiveObject : public CObject
{
public:
	enum EMLiveType
	{
		MONSTER,
		PC,
	};

	CLiveObject()
	{
	}

	CLiveObject(string strName, int hp, int atk, int def) :
		m_def(def)
	{
		m_emLiveType = EMLiveType::MONSTER;
		CreateObject(strName, EMType::LIVE_OBJECT, hp, atk);
	}

	~CLiveObject();

protected:
	int m_def;	// 방어력
	EMLiveType m_emLiveType;

public:
	EMLiveType GetLiveType() const {
		return m_emLiveType;
	}
	int GetDef() const { return m_def; }
};


class CNonLiveObject : public CObject
{
public:
	enum EMNonLiveType
	{
		ITEM, // 아이템
		TRAP, // 함정
	};

	CNonLiveObject(string strName, EMNonLiveType emNonLiveType, int hp, int atk)
	{
		m_emNonLiveType = emNonLiveType;
		CreateObject(strName, EMType::NONLIVE_OBJECT, hp, atk);
	}
	~CNonLiveObject();

private:
	EMNonLiveType m_emNonLiveType;

public:
	EMNonLiveType GetNonLiveType() const {
		return m_emNonLiveType;
	}
};

class CPCLiveObject : public CLiveObject
{
public:
	CPCLiveObject(string strName, int hp, int atk, int def)
	{
		m_def = def;
		m_emLiveType = EMLiveType::PC;
		CreateObject(strName, EMType::LIVE_OBJECT, hp, atk);
	}
	~CPCLiveObject();
	void RunAction(CObject &object);
};