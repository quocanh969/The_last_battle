#define _CRT_SECURE_NO_WARNINGS
#include"cDoiQuan.h"

void main()
{
	//Bài tập nhóm tuần 10 lý thuyết OOP của thầy Phạm Nguyễn Sơn Tùng
	//Các thành viên nhóm:
	//Trần Quốc Anh - MSSV: 1612018
	//Nguyễn Hồng Đăng - MSSV: 1612082
	//Phan Hải Bình - MSSV: 1612041
	
	cDoiQuan team[2];
	int i = 0;

	freopen("input.txt", "r", stdin);

	string trash;//xóa rác ở cuối câu

	while (!cin.eof())
	{
		team[i].nhap();
		team[i].capNhatDoi();
		getline(cin, trash);
		i++;
	}

	fclose(stdin);
	
	freopen("output.txt", "w", stdout);
	//Chỉ có 2 team đánh nhau nên số phần tử là 2
	if (team[0].giaoTranh(team[1]) == 1)
	{
		team[0].xuat();
	}
	else
	{
		team[1].xuat();
	}

	fclose(stdout);
}