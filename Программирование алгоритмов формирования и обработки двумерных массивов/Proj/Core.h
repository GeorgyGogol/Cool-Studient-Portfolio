#pragma once

#define LAB_NUM "7"
#define LAB_TEXT "���������������� ���������� ������������ � ��������� ��������� ��������"
#define VAR "27"
#define VAR_TEXT "����������� ������������ ��������� ������� X(m, n) � Y(n, k). �������� ������ Z ����� ����������� � ��������� ������� ������� ������� X ������������ ��������� ��������������� ������ ������� Y."
#define FIO "������� ������� ����������"
#define GROUP "���-2051"

namespace Core {

int GetRandom(int min = -15000, int max = 15000);

class cMatrix
{
public:
	cMatrix(int width, int height);
	cMatrix(int side);
	~cMatrix();

private:
	int **Mas;
	int Width, Height;

public:
	int get(int x, int y) const;
	void set(int x, int y, int num);

	int get_productRow(int row) const;
};

}

