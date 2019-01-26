#include "cCungThu.h"

void cCungThu::nhap()
{
	cQuan::nhap();
	if (m_equipment == "YES")
	{
		m_attack *= 1.5;
	}
}

string cCungThu::getVaiTro()
{
	return "A";
}

cCungThu::cCungThu()
{
}


cCungThu::~cCungThu()
{
}
