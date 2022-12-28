#pragma once

#define LAB_NUM "7"
#define LAB_TEXT "Программирование алгоритмов формирования и обработки двумерных массивов"
#define VAR "27"
#define VAR_TEXT "Сформируйте произвольные двумерные массивы X(m, n) и Y(n, k). Получите массив Z путем прибавления к элементам каждого столбца массива X произведения элементов соответствующей строки массива Y."
#define FIO "Гоголев Георгий Михайлович"
#define GROUP "БИК-2051"

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

