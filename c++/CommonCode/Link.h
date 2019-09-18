#pragma once

class CNode
{
public:
	CNode();
	CNode(int value);
	int GetValue() const {
		return m_value;
	}
	void SetNext(CNode *pNext)
	{
		m_pNext = pNext;
	}

	CNode* GetNext() {
		return m_pNext;
	}
	
private:
	int m_value;
	CNode *m_pNext;
};

class CLink
{
private:
	CNode *m_pFirst;
	CNode *m_pLast;
	int m_size;
public:
	CLink();
	~CLink();

	void PushFront(int value);
	void PushBack(int value);
	void Remove(int value);
	void Clear();
	CNode* GetFirst()
	{
		return m_pFirst;
	}
};

