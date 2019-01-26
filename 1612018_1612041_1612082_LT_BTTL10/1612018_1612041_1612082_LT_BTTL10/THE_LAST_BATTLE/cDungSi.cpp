#include "cDungSi.h"

void cDungSi::nhap()
{
	cQuan::nhap();
	if (m_equipment == "YES")
	{
		m_defend *= 2;
	}
}

string cDungSi::getVaiTro()
{
	return "V";
}

cDungSi::cDungSi()
{
}


cDungSi::~cDungSi()
{
}
