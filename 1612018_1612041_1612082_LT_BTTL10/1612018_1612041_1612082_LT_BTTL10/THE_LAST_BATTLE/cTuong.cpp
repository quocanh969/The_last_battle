#include "cTuong.h"

void cTuong::nhap()
{
	cQuan::nhap();
	cin >> m_experience;
}

void cTuong::xuat()
{
	cQuan::xuat();
	cout << " " << m_experience;
}

string cTuong::getVaiTro()
{
	return "AG";
}

float cTuong::getExperience()
{
	return m_experience;
}

//Hàm so sánh 2 tướng quân với nhau trong cùng một đội, để chọn thủ lĩnh tối cao
bool cTuong::operator>(cTuong a)
{
	if (m_experience > a.m_experience)
	{
		return true;
	}
	else if (m_experience == a.m_experience)
	{
		int so_sanh = Attack(&a) + Defend(&a);
		if (so_sanh < 0)return false;
		else if (so_sanh == 0)
		{
			if (m_strength >= a.m_strength)return true;
			else return false;
		}
		else return true;
	}
	else
	{
		return false;
	}
}

cTuong::cTuong()
{
}


cTuong::~cTuong()
{
}
