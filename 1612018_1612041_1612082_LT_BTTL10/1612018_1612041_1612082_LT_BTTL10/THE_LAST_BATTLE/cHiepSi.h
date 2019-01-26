#pragma once
#include"cQuan.h"
class cHiepSi : public cQuan
{
public:
	void nhap();
	string getVaiTro();
	cHiepSi();
	cHiepSi(cQuan &);
	~cHiepSi();
};

