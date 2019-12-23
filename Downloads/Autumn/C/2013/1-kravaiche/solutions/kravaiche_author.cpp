#include <cstdio>
using namespace std;
int c, n;
int a[100000];

void printRange(int from, int to)
{ 	
	printf ("%d", from);
	from ++;

	while (from <= to)
	{
		printf (" %d", from);
		from ++;
	}

	printf("\n");
}

int main ()
{
	scanf ("%d%d", &c, &n);

	int i, temp, acc = 0; 
	for(i = 1; i <= n; i ++)
	{
		scanf ("%d", &temp);
		acc = (acc + temp)%c;
		if(temp % c == 0)
		{
			printf ("%d\n", i); // single number answer
			break;
		}
		else
		if (acc == 0 || a[acc]) // whole of the prefix or a subsequence
		{
			//based on the pigeonhole principle we'll enter here at least once
			printRange(a[acc] + 1, i);
			break;
		}
		a[ acc ] = i;
	}

	return 0;
}