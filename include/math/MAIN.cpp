#include <iostream>
#include <cmath>
#include "Gauss_method.h"
#include "Line+Circle.h"
#include "RefAcrossLine.h"
using namespace std;

int main() // Ã›…Õ ƒÀﬂ √¿”——¿
{
	cout << "Choose the act." << endl;
	cout << "1) Gauss method" << endl << "2) Line + Circle: finding parameter of shift line for to touching circle. " << endl << "3) Reflection across a Line(Segment): point" << endl << "Your choice: ";
	int k = -1;
	cin >> k;
	switch(k){
		case 1: {
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
	cout << "Size of system: "<<SLAU.size()*SLAU[0].size();
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
			break;
		}
		case 2: {
			double A = 0, B = 0, *C_1 = 0,*C_2 = 0, b = 0, a = 0, R = 0;
	cout << "Input coeff of circle (x - a)^2+(y-b)^2=R^2 (a b R^2)";
	cin >> a >> b >> R;
	cout << "Input coeff of line Ax+By+C=0 (A B)";
	cin >> A >> B;
	PtoC(a,b,A,B,R,C_1,C_2);
	cout << "C_1 =" << (*C_1) << "C_2 = " << (*C_2);
	system("pause");
			break;
		}
		case 3:{
			double A = 0,B = 0, C = 0;
			double x = 0,y = 0, xR =0 , yR = 0;
			cout << "Input the line Ax+By+C=0: (A B C): ";
			cin >> A >> B >> C;
			cout << "Input pont for reflection: (x y): ";
			cin >> x >> y;
			Reflection(xR,yR,x,y,A,B,C);
			cout << "Symmetric point is: (" << xR << "," << yR << ")" << endl;
			break;
		}
	}
}
/* Ã›…Õ ƒÀﬂ À»Õ»ﬂ œÀﬁ— Œ –”∆ÕŒ—“‹
int main() {

return 0;

}
*/
