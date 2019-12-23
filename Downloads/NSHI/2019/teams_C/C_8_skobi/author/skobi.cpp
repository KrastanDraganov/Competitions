#include <stdlib.h>
#include <climits>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int MAX_N=60;
int x[MAX_N];
char op[MAX_N-1];
long long int cmin[MAX_N][MAX_N];
long long int cmax[MAX_N][MAX_N];

long long int operation(long long int x, char op, long long int y)
{
	long long result;
	if (op=='+')
		result = x+y;
	else if (op=='*')
		result = x*y;
	else
	{
		cerr << "Error - invalid operation " << op << endl;
		exit(1);
	}
        return result;
}

int main(void)
{
	string s;
	while(cin >> s)
	{
		istringstream str(s);
		int n=0;
		while (str >> x[n])
			str >> op[n++];
		for(int i=0;i<n;i++)
		{
			cmin[i][i] = cmax[i][i] = x[i];
		}

		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				cmin[i][j] = LLONG_MAX;
				cmax[i][j] = LLONG_MIN;
			}

		for (int diag=1; diag<n; diag++)
			for (int row=0; row<n-diag; row++)
				for (int i=row; i<row+diag; i++){
				    cmin[row][row+diag]=min(cmin[row][row+diag],operation(cmin[row][i],op[i],cmin[i+1][row+diag]));
					cmax[row][row+diag]=max(cmax[row][row+diag],operation(cmax[row][i],op[i],cmax[i+1][row+diag]));
				}

		cout << cmin[0][n-1] << " " << cmax[0][n-1] << endl;
	}
	return 0;
}
/* End of File skobi */
