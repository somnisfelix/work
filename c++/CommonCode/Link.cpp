#include "Link.h"

CNode::CNode()
{
}

CNode::CNode(int value)
	: m_value(value)
{
}

CLink::CLink()
	: m_pFirst(nullptr), m_pLast(nullptr), m_size(0)
{
}


CLink::~CLink()
{
}

void CLink::PushFront(int value)
{
	CNode *pNewNode = new CNode(value);
	if (m_pFirst == nullptr)
	{
		m_pFirst = pNewNode;
		m_pLast = pNewNode;
	}
	else {
		pNewNode->SetNext(m_pFirst);
		m_pFirst = pNewNode;
	}
	m_size++;
}

void CLink::PushBack(int value)
{
	CNode *pNewNode = new CNode(value);
	if (m_pFirst == nullptr)
	{
		m_pFirst = pNewNode;
		m_pLast = pNewNode;
	}
	else {
		m_pLast->SetNext(pNewNode);
		m_pLast = pNewNode;
	}

	m_size++;
}

void CLink::Remove(int value)
{
	CNode *pCur = m_pFirst;
	CNode *pNext;
	while (pCur != nullptr)
	{
		pNext = pCur->GetNext();
		if (pNext != nullptr && pNext->GetValue() == value)
		{
			pCur->SetNext(pNext->GetNext());
			delete pNext;
			break;
		}
		pCur = pNext;
	}
}

void CLink::Clear()
{
	CNode *pCur = m_pFirst;
	CNode *pNext;
	while (pCur != nullptr)
	{
		pNext = pCur->GetNext();
		delete pCur;
		pCur = pNext;
	}
}
