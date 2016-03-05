#include <iostream>
#include <vector>
#include <cmath>
// Решение СЛУ методом Гаусса с выбором главного элемента по столбцу
// На входе: матрица коэффициентов, вектор правых частей.
// На выходе: заполненный вектор решения

using namespace std;
int Gauss_metod(vector < vector<double> > a,vector<double> & ans)
{
	////////////// Задаем размеры массива строки = n столбцы = m
	int m = a[0].size() - 1;
	int n = a.size();
	//////////////
	vector<int> pos (m, -1); // Переменная д
		for(int col = 0, row = 0; col<m && row<n;++col) // 				находим опорный элемент(max) меняем 
			{											// строки относительно него и прямой ход метода Гаусса
				int sel = row;
					for (int i = row; i<n; ++i)
					// // // // /// //
						if ( abs(a[i][col]) > abs (a[sel][col])) sel = i; // Находим max и запоминаем номер его строки.
					// // // // /// //
				if (abs(a[sel][col]) < 0.0000001) continue; // Если max = 0, то удаляем столбец
				for (int i = col; i <=m; ++i) swap(a[sel][i],a[row][i]);// Свапнуть элемент бОльший с меньшим	
				pos[col] = row; // Запомнить номер строки в которой
								  //  столбец номера col больше нуля 
		//////				Основной цикл метода Гаусса 
	for (int i = 0; i<n;i++) // n - кол-во столбцов
			if(i != row) //строка i не равна строке row
			{
				double c = a[i][col]/a[row][col];
				for(int j = 0; j <= m; ++j){a[i][j] = a[i][j] - a[row][j] * c;} // Обнуляем все строки меньше max
			}
		//////
		row++;
			}
			////
			 ans.assign(m-1,0);
			 	for (int i=0; i<m;++i)
						if (where[i] != -1)
							ans[i] = a[where[i]][m]/a[where[i]][i];
							
				for (int i=0; i<n; ++i)
				{
						double sum = 0;
						for (int j = 0; j<m;++j)
						sum = sum + ans[j]*a[i][j];
							if (abs(sum - a[i][m])>0.0000001) return 0;
				}
			///////	
		for (int i=0; i<m; ++i)
			if (where[i] == -1)
				return 5;
			///////
	return 1;
			////
}
int main()
{
	int n,m,PoW;
	double kkk;
	cout << "Input the number of rows: ";
	cin >> n;
	cout << "Input the number of colomns: ";
	cin >> m;
	
	vector< vector<double> > SLAU(n,vector<double>(m+1));
	vector<double> answ; // 
	for(int i = 0; i<n;++i)
	{
	for(int j = 0; j<m+1;++j)
		{
			cin >> kkk;
			SLAU[i][j] = kkk;
		}
	}
		for(int i = 0; i<n;++i)
	{
	for(int j = 0; j<m+1;++j)
		{
			cout << "[" << i << "]" << "[" << j << "] ="<< SLAU[i][j]  << " " ;
		}
		cout << endl;
	}
	cout << SLAU.size()*SLAU[0].size();
	cout << endl;
	///////////
			PoW = Gauss_metod(SLAU,answ);
			switch(PoW)
			{
			case 5: cout << "Infinity"; break;
			case 0: cout << "There are no answers"; break;
				case 1: 
				{
					for(int i = 0; i<=answ.size();++i)
					{
						cout << answ[i] << " ";
					}
					break;
				}
			}
		cout << endl;
		system("pause");
}
