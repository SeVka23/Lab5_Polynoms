#include "TMonom.h"

TMonom::TMonom(int cval, int ival)
{
  coeff = cval;
  index = ival;
}

TDatValue* TMonom::GetCopy()
{
  TDatValue* temp = new TMonom(coeff, index);
  return temp;
}

void TMonom::SetCoeff(int cval)
{
  coeff = cval;
}

int TMonom::GetCoeff()
{
  return coeff;
}

void TMonom::SetIndex(int ival)
{
  index = ival;
}

int TMonom::GetIndex()
{
  return index;
}

TMonom& TMonom::operator=(const TMonom& tm)
{
  coeff = tm.coeff;
  index = tm.index;
  return *this;
}

int TMonom::operator==(const TMonom& tm)
{
  return ((coeff == tm.coeff) && (index == tm.index));
}

int TMonom::operator<(const TMonom& tm)
{
  return index < tm.index;
}
