#include "cQuan.h"

void cQuan::nhap()
{
	cin >> m_code;
	cin >> m_attack;
	cin >> m_defend;
	cin >> m_equipment;
	cin >> m_strength;
}

void cQuan::xuat()
{
	cout << m_code << " " << m_attack << " " << m_defend << " " << m_equipment << " " << m_strength;
}

//Hàm tấn công, một binh lính tấn công kẻ thủ
//Nếu tấn công thành công thì trả về 1
//Nếu thất bại thì trả về -1
int cQuan::Attack(cQuan *a)
{
	if (m_attack >= a->m_defend)return 1;
	else return -1;
}

//Hàm phòng thủ, một binh lính phòng thủ trước tấn công của kẻ thủ
//Nếu phòng thủ thành công thì trả về 1
//Nếu thất bại thì trả về -1
int cQuan::Defend(cQuan *a)
{
	if (m_defend > a->m_attack)return 1;
	else return -1;
}

//Điểm attack và defend thay đổi tùy vào experience của tướng quân
void cQuan::setPoint(float a)
{
	m_attack *= a;
	m_defend *= a;
}

//Sự hy sinh cho chiến thắng
void cQuan::hySinh()
{
	m_attack -= 20;
	m_defend -= 20;
}

string cQuan::getCode()
{
	return m_code;
}

string cQuan::getEquip()
{
	return m_equipment;
}

float cQuan::getAttack()
{
	return m_attack;
}

float cQuan::getDefend()
{
	return m_defend;
}

int cQuan::getStrength()
{
	return m_strength;
}

cQuan::cQuan()
{
}


cQuan::~cQuan()
{
}
