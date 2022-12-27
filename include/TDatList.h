#pragma once
#include "TDatLink.h"
#include "TDatValue.h"
enum TLinkPos
{
	FIRST,
	CURRENT,
	LAST
};
class TDatList
{
protected:
	PTDatLink pFirst;
	PTDatLink pLast;
	PTDatLink pCurrLink;
	PTDatLink pPrevLink;
	PTDatLink pStop;
	int currPos;
	int listLen;

protected:
	PTDatLink GetLink(PTDatValue pVal = NULL, PTDatLink pLink = NULL);
	void DelLink(PTDatLink pLink);

public:
	TDatList();
	~TDatList();
	PTDatValue GetDatValue(TLinkPos mode = CURRENT);
	virtual int IsEmpty();
	int GetListLength();

	void SetCurrentPos(int pos);
	int GetCurrentPos();
	virtual void Reset();
	virtual int IsListEnded();
	void GoNext();

	virtual void InsFirst(PTDatValue pVal = NULL);
	virtual void InsLast(PTDatValue pVal = NULL);
	virtual void InsCurrent(PTDatValue pVal = NULL);

	virtual void DelFirst();
	virtual void DelCurrent();
	virtual void DelList();
};