#pragma once
#include<iostream>
#include<vector>
#include<stack>

#include<string>

using namespace std;
class cQuan
{
protected:
	string m_code, m_equipment;
	float m_attack, m_defend;
	int m_strength;
public:
	virtual void nhap();
	virtual void xuat();
	virtual string getVaiTro() = 0;
	virtual int Attack(cQuan *);
	virtual int Defend(cQuan *);

	//Chuỗi hàm get();
	virtual string getCode();
	virtual string getEquip();
	virtual float getAttack();
	virtual float getDefend();
	virtual int getStrength();

	//Hàm getExperience() của lớp tướng quân
	//Việc khai báo trong lớp cQuan là nhằm giúp cho việc tướng quân được xét là con trỏ của cQuan dễ dàng hơn
	virtual float getExperience()
	{
		return 0;
	};

	//Hàm thay đổi chỉ số tùy vào experience
	virtual void setPoint(float);

	//Sự hy sinh khi chiến thắng là mất 20 điểm attack và 20 điểm defend
	virtual void hySinh();

	cQuan();
	~cQuan();
};

