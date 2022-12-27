#pragma once
#include "TDatValue.h"
#include "TRootLink.h"

class TDatLink;
typedef TDatLink* PTDatLink;

class TDatLink : public TRootLink
{
protected:
	PTDatValue pValue;
public:
	TDatLink(PTDatValue pVal = NULL, PTRootLink pN = NULL) : TRootLink(pN)
	{
		pValue = pVal;
	}
	void SetDatValue(PTDatValue pVal);
	PTDatValue GetDatValue();
	PTDatLink GetNextDatLink();
	friend class TDatList;
};