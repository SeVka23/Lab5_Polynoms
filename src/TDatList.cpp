#include "TDatList.h"

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
  PTDatLink temp = new TDatLink(pVal, pLink);
  if (temp == NULL) throw "error";
  return temp;
}

void TDatList::DelLink(PTDatLink pLink)
{
  if (pLink != NULL)
  {
    if (pLink->pValue != NULL)
      delete pLink->pValue;
    delete pLink;
  }
}

TDatList::TDatList()
{
  pFirst = NULL;
  pLast = NULL;
  pStop = NULL;
  listLen = 0;
  Reset();
}

TDatList::~TDatList()
{
  DelList();
}

PTDatValue TDatList::GetDatValue(TLinkPos mode)
{
  PTDatLink temp;
  switch (mode)
  {
  case FIRST:
    temp = pFirst;
    break;
  case LAST:
    temp = pLast;
    break;
  default:
    temp = pCurrLink;
    break;
  }
  return (temp == NULL) ? NULL : temp->pValue;
}

int TDatList::IsEmpty()
{
  return pFirst == pStop;
}

int TDatList::GetListLength()
{
  return listLen;
}

void TDatList::SetCurrentPos(int pos)
{
  Reset();
  for (int i = 0; i < pos; i++, GoNext());
}

int TDatList::GetCurrentPos()
{
  return currPos;
}

void TDatList::Reset()
{
  pPrevLink = pStop;
  if (IsEmpty())
  {
    pCurrLink = pStop;
    currPos = -1;
  }
  else
  {
    pCurrLink = pFirst;
    currPos = 0;
  }
}

int TDatList::IsListEnded()
{
  return pCurrLink == pStop;
}

void TDatList::GoNext()
{
  if (pCurrLink != pStop)
  {
    pPrevLink = pCurrLink;
    pCurrLink = pCurrLink->GetNextDatLink();
    currPos++;
  }
}

void TDatList::InsFirst(PTDatValue pVal)
{
  PTDatLink temp = GetLink(pVal, pFirst);
  if (temp != NULL)
  {
    pFirst = temp;
    listLen++;
    if (listLen == 1)
    {
      pLast = temp;
      Reset();
    }
    else if (currPos == 0)
      pCurrLink = temp;
    else
      currPos++;
  }
}

void TDatList::InsLast(PTDatValue pVal)
{
  PTDatLink temp = GetLink(pVal, pStop);
  if (temp != NULL)
  {
    if (pLast != NULL)
      pLast->SetNextLink(temp);
    pLast = temp;
    listLen++;
    if (listLen == 1)
    {
      pFirst = temp;
      Reset();
    }
    if (IsListEnded())
      pCurrLink = temp;
  }
  else
    throw "error";
}

void TDatList::InsCurrent(PTDatValue pVal)
{
  if (IsEmpty() || pCurrLink == pFirst)
    InsFirst(pVal);
  else if (IsListEnded())
    InsLast(pVal);
  else if (pPrevLink == pStop)
    throw "List No Mem";
  else
  {
    PTDatLink temp = GetLink(pVal, pCurrLink);
    if (temp != NULL)
    {
      pCurrLink = temp;
      pPrevLink->SetNextLink(temp);
      listLen++;
    }
  }
}

void TDatList::DelFirst()
{
  if (IsEmpty())
    throw "List is empty";
  else
  {
    PTDatLink temp = pFirst;
    pFirst = (PTDatLink)pFirst->GetNextLink();
    DelLink(temp);
    listLen--;
  }
  if (IsEmpty())
  {
    pLast = pStop;
    Reset();
  }
  else if (currPos == 0)
    pCurrLink = pFirst;
  else if (currPos == 1)
    pPrevLink = pStop;
  if (currPos > 0)
    currPos--;
}

void TDatList::DelCurrent()
{
  if (pCurrLink == pStop)
    throw "No link in current position";
  else if (pCurrLink == pFirst)
    DelFirst();
  else
  {
    PTDatLink temp = pCurrLink;
    pCurrLink = pCurrLink->GetNextDatLink();
    pPrevLink->SetNextLink(pCurrLink);
    DelLink(temp);
    listLen--;
    if (pCurrLink == pLast)
    {
      pLast = pPrevLink;
      pCurrLink = pStop;
    }
  }
}

void TDatList::DelList()
{
  while (!IsEmpty())
    DelFirst();
  pFirst = pLast = pStop = pCurrLink = pPrevLink;
  currPos = -1;
}
