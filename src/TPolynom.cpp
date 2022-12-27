#include "TPolynom.h"

TPolynom::TPolynom(int monoms[][2], int km)
{
  PTMonom pMonom = new TMonom(0, -1);
  pHead->SetDatValue(pMonom);
  for (int i = 0; i < km; i++)
  {
    if (monoms[i][1] > 999 || monoms[i][1] < 0)
      throw "error";
    pMonom = new TMonom(monoms[i][0], monoms[i][1]);
    InsLast(pMonom);
  }
}

TPolynom::TPolynom(TPolynom& q)
{
  PTMonom pMonom = new TMonom(0, -1);
  pHead->SetDatValue(pMonom);
  for (q.Reset(); !q.IsListEnded(); q.GoNext())
  {
    PTMonom pMonom = q.GetMonom();
    InsLast(pMonom->GetCopy());
  }
}

PTMonom TPolynom::GetMonom()
{
  return (PTMonom)GetDatValue();
}

TPolynom& TPolynom::operator+(TPolynom& q)
{
  PTMonom pm, qm, rm;
  Reset();
  q.Reset();
  while (true)
  {
    pm = GetMonom();
    qm = q.GetMonom();
    if (pm->index < qm->index)
    {
      rm = new TMonom(qm->coeff, qm->index);
      InsCurrent(rm);
      q.GoNext();
    }
    else if (pm->index > qm->index)
      GoNext();
    else
    {
      if (pm->index == -1)
        break;
      pm->coeff += qm->coeff;
      if (pm->coeff != 0)
      {
        GoNext();
        q.GoNext();
      }
      else
      {
        DelCurrent();
        q.GoNext();
      }
    }
  }
  return *this;
}

TPolynom& TPolynom::operator=(TPolynom& q)
{
  DelList();
  for (q.Reset(); !q.IsListEnded(); q.GoNext())
  {
    PTMonom pMonom = q.GetMonom();
    InsLast(pMonom->GetCopy());
  }
  return *this;
}

int TPolynom::CalculatePolynom(int x, int y, int z)
{
  int result = 0;
  int indexX;
  int indexY;
  int indexZ;

  for (Reset(); !IsListEnded(); GoNext())
  {
    indexX = GetMonom()->index / 100;
    indexY = (GetMonom()->index / 10) % 10;
    indexZ = GetMonom()->index % 10;
    result += GetMonom()->coeff * std::pow(x, indexX) * std::pow(y, indexY) * std::pow(z, indexZ);
  }
  return result;
}

std::ostream& operator<<(std::ostream& os, TPolynom& q)
{
  int k = 1;
  for (q.Reset(); !q.IsListEnded(); q.GoNext(), k++)
  {
    if (!(k == 1))
      std::cout << " +" << *q.GetMonom();
    else
      std::cout << *q.GetMonom();
  }
  return os;
}

std::istream& operator>>(std::istream& is, TPolynom& q)
{
  int coef = 0;
  int amountOfMonom = 0;
  std::string indexStr;
  if (q.listLen != 0)
    q.DelList();
  std::cout << "Enter the count of monoms: ";
  is >> amountOfMonom;
  for (q.Reset(); q.currPos < amountOfMonom; q.GoNext())
  {
    std::cout << "Enter coefficient: ";
    is >> coef;
    if (coef == 0)
      continue;
    std::cout << "Enter the convolution of degrees(x,y,z)"
      << std::endl
      << "(3-digit number, in a row without symbols : ";
    is >> indexStr;
    if (indexStr.length() > 3)
      throw "error";
    for (int i = 0; i < indexStr.length(); i++)
    {
      if (isdigit(indexStr[i]) == 0)
        throw "error";
    }

    PTMonom temp = new TMonom(coef, atoi(indexStr.c_str()));
    q.InsLast(temp);
  }
  return is;
}
