#pragma once
#include"cQuan.h"

class cTuong : public cQuan
{
private:
	float m_experience;
public:
	void nhap();
	void xuat();
	string getVaiTro();
	float getExperience();
	bool operator>(cTuong);
	cTuong();
	~cTuong();
};

