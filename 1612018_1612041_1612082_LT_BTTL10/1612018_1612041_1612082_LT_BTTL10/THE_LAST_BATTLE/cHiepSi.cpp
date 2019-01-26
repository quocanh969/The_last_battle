#include"cHiepSi.h"

void cHiepSi::nhap()
{
	cQuan::nhap();
	if (m_equipment == "YES")
	{
		m_defend *= 3;
		m_attack *= 3;
	}
}

string cHiepSi::getVaiTro()
{
	return "K";
}

cHiepSi::cHiepSi()
{
}

cHiepSi::cHiepSi(cQuan &a)
{
	m_code = a.getCode();
	m_attack = a.getAttack();
	m_defend = a.getDefend();
	m_equipment = a.getEquip();
	m_strength = a.getStrength();
}

cHiepSi::~cHiepSi()
{
}
