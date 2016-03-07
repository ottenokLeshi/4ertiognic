#ifndef GAUSS_METH_H
#define GAUSS_METH_H
#include <iostream>
#include <vector>
#include <cmath>
// ������� ��� ������� ������ � ������� �������� �������� �� �������
// �� �����: ������� �������������, ������ ������ ������.
// �� ������: ����������� ������ �������

using namespace std;
int Gauss_metod(vector < vector<double> > a,vector<double> & ans)
{
	////////////// ������ ������� ������� ������ = n ������� = m
	int m = a[0].size() - 1;
	int n = a.size();
	//////////////
	vector<int> pos (m, -1); // ���������� �
		for(int col = 0, row = 0; col<m && row<n;++col) // 				������� ������� �������(max) ������ 
			{											// ������ ������������ ���� � ������ ��� ������ ������
				int sel = row;
					for (int i = row; i<n; ++i)
					// // // // /// //
						if ( abs(a[i][col]) > abs (a[sel][col])) sel = i; // ������� max � ���������� ����� ��� ������.
					// // // // /// //
				if (abs(a[sel][col]) < 0.0000001) continue; // ���� max = 0, �� ������� �������
				for (int i = col; i <=m; ++i) swap(a[sel][i],a[row][i]);// �������� ������� ������� � �������	
				pos[col] = row; // ��������� ����� ������ � �������
								  //  ������� ������ col ������ ���� 
		//////				�������� ���� ������ ������ 
	for (int i = 0; i<n;i++) // n - ���-�� ��������
			if(i != row) //������ i �� ����� ������ row
			{
				double c = a[i][col]/a[row][col];
				for(int j = 0; j <= m; ++j){a[i][j] = a[i][j] - a[row][j] * c;} // �������� ��� ������ ������ max
			}
		//////
		row++;
			}
			////
			 ans.assign(m-1,0);
			 	for (int i=0; i<m;++i)
						if (pos[i] != -1)
							ans[i] = a[pos[i]][m]/a[pos[i]][i];
							
				for (int i=0; i<n; ++i)
				{
						double sum = 0;
						for (int j = 0; j<m;++j)
						sum = sum + ans[j]*a[i][j];
							if (abs(sum - a[i][m])>0.0000001) return 0;
				}
			///////	
		for (int i=0; i<m; ++i)
			if (pos[i] == -1)
				return 5;
			///////
	return 1;
			////
}
#endif

