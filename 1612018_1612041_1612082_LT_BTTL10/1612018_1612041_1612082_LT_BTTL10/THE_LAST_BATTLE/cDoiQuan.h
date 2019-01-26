#pragma once
#include"cQuan.h"
#include"cTuong.h"
#include"cDungSi.h"
#include"cCungThu.h"
#include"cHiepSi.h"
class cDoiQuan
{
private:
	string ten;
	int soLuong;
	cQuan *tuongQuan = NULL;
	//Khởi tạo tướng quân chưa có ai hết
	//Nếu như xuất hiện 2 tướng quan thì xét xem ai có kinh nghiêm lớn hơn
	//Người thua cuộc sẽ hiệp sĩ
	
	cQuan **doi_quan;


	/*stack<cQuan*> doi_quan;
	stack<cQuan*>::operator= iterator;*/

public:
	void nhap();
	void capNhatDoi();
	//tùy theo chỉ số kinh nghiệm của tướng quân mà attack và defend của lính thay đổi

	int giaoTranh(cDoiQuan &a);

	void xuat();

	cDoiQuan();
	~cDoiQuan();
};

