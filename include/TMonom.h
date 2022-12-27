#pragma once
#include <iostream>
#include "TDatValue.h"
class TMonom;
typedef TMonom* PTMonom;

class TMonom : public TDatValue
{
protected:
	int coeff;
	int index;
public:
	TMonom(int cval = 1, int ival = 0);
	virtual TDatValue* GetCopy();
	void SetCoeff(int cval);
	int GetCoeff();
	void SetIndex(int ival);
	int GetIndex();
	TMonom& operator=(const TMonom& tm);
	int operator==(const TMonom& tm);
	int operator<(const TMonom& tm);
	friend std::ostream& operator<<(std::ostream& os, TMonom& q)
	{
		int powX = q.index / 100;
		int powY = (q.index / 10) % 10;
		int powZ = q.index % 10;
		if (q.coeff != 0)
		{
			os << " " << q.coeff;
			if (powX != 0)
				os << "X^" << powX;
			if (powY != 0)
				os << "Y^" << powY;
			if (powZ != 0)
				os << "Z^" << powZ;
		}
		return os;
	}
	friend class TPolynom;
};