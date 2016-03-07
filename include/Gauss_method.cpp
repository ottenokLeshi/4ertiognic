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
