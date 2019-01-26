#include "cDoiQuan.h"

void cDoiQuan::nhap()
{
	string ma;
	getline(cin, ma);
	//Tách tên ra, với số lượng chữ số là ở sau cái tên
	int i = ma.length() - 1;
	while (ma[i] != ' ')
	{
		i--;
	}

	soLuong = stoi(ma.substr(i)) - 1;
	ten = ma.erase(i);

	doi_quan = new cQuan*[soLuong];

	//atoi((ma.substr(i, ma.length() - 1 - i)).c_str);



	//Đọc vào thông tin tướng, chỉ có một vị tướng
	for (int j = 0; j < soLuong; j++)
	{
		cin >> ma;
		if (ma != "AG")
		{
			cQuan* t = NULL;
			if (ma == "A")
			{
				t = new cCungThu;
				t->nhap();
			}
			else if (ma == "V")
			{
				t = new cDungSi;
				t->nhap();
			}
			else if (ma == "K")
			{
				t = new cHiepSi;
				t->nhap();
			}
			doi_quan[soLuong - 1 - j] = t;
		}
		else
		{
			if (tuongQuan == NULL)
			{
				tuongQuan = new cTuong;
				tuongQuan->nhap();
				j--;
			}
			else
			{
				cTuong *t = new cTuong;
				t->nhap();
				if (t > tuongQuan)
				{
					cQuan *temp = tuongQuan;
					tuongQuan = t;
					cQuan *a = new cHiepSi(*temp);
					delete temp;
					doi_quan[soLuong - 1 - j] = a;
				}
			}
		}
	}
}

void cDoiQuan::capNhatDoi()
{
	float point;
	//điểm point để nhân vào chỉ số sẽ phụ thuộc vào kinh nghiệm của tướng quân
	if (tuongQuan->getExperience() == 0)
	{
		point = 0.5;
	}
	else if (tuongQuan->getExperience() <= 2)
	{
		point = 1.2;
	}
	else if (tuongQuan->getExperience() <= 5)
	{
		point = 1.5;
	}
	else
	{
		point = 2;
	}

	for (int i=0;i<soLuong;i++)
	{
		doi_quan[i]->setPoint(point);
	}
}

int cDoiQuan::giaoTranh(cDoiQuan &a)
{
	int i = soLuong - 1 , j = a.soLuong - 1;
	int atk, def;
	int kt1 = 1, kt2 = 1;//Kiểm tra xem tướng quân đã xuất trận chưa??
	while (soLuong != 0 && a.soLuong != 0)
	{
		//Các binh lính đánh nhau
		atk = doi_quan[i]->Attack(a.doi_quan[j]);
		def = doi_quan[i]->Defend(a.doi_quan[j]);
		if (atk + def > 0)
		{
		flag1:;
			doi_quan[i]->hySinh();		
			if (j == 0 && kt1 == 1)
			{//Nếu như binh lính một trong 2 bên hết và tướng quân còn sống thì tướng quân đánh tiếp
				kt1 = 0;
				a.doi_quan[0] = a.tuongQuan;
			}
			else
			{
				delete a.doi_quan[j];
				j--;
				a.soLuong--;
			}
		}
		else if (atk + def == 0)
		{
			//Trong bài này thì trường hợp dấu " = " rất ít xảy ra
			//nhưng nếu xảy ra thì bên team đánh trước sẽ thắng
			if (doi_quan[i]->getStrength() >= a.doi_quan[j]->getStrength())
			{
				goto flag1;
			}
			else
			{
				goto flag2;
			}
		}
		else
		{
		flag2:;
			a.doi_quan[j]->hySinh();		
			if (i == 0 && kt2 == 1)
			{//Nếu như binh lính một trong 2 bên hết và tướng quân còn sống thì tướng quân đánh tiếp
				kt2 = 0;
				doi_quan[0] = tuongQuan;
			}
			else
			{
				delete doi_quan[i];
				i--;
				soLuong--;
			}

		}
	}

	//Nếu đội đánh trước thắng thì return 1
	//Nếu thất bại thì return -1
	if (a.soLuong == 0)return 1;
	else return -1;
}

void cDoiQuan::xuat()
{
	if (doi_quan[0]->getVaiTro() == "AG")
	{
		cout << ten << " 1";
		cout << endl << doi_quan[0]->getVaiTro() << " ";
		doi_quan[0]->xuat();
	}
	else
	{
		cout << ten << " " << soLuong + 1;
		cout << endl << tuongQuan->getVaiTro() << " ";
		tuongQuan->xuat();
		for (int i = 0; i < soLuong; i++)
		{
			cout << endl << doi_quan[soLuong - 1 -i]->getVaiTro() << " ";
			doi_quan[soLuong - 1 - i]->xuat();
		}
	}
}

cDoiQuan::cDoiQuan()
{
}


cDoiQuan::~cDoiQuan()
{
}
