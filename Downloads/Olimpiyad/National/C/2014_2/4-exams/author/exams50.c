#include <stdio.h>

#define MAXN 1000000

long long max[MAXN];
long long current[MAXN];
long long n, m;
long long answ;

void readInput()
{
	int i;
	scanf("%lld %lld", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &max[i]); 
	}
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &current[i]); 
	}
}

void solve()
{
	long long i, currentSum;
	for (answ = 0; ; answ++)
	{
		//printf("%ld", answ);
		currentSum = 0;
		for (i = 0; i < n; i++)
		{
			if (current[i] + answ > max[i])
			{
				currentSum += max[i];
			}
			else
			{
				currentSum += current[i] + answ;
			}
		}
		//if (answ == 209895)
		//{
		//	printf(" %ld\n", currentSum);
		//}
		
		if (currentSum >= m)
		{
			//printf(" %ld\n", currentSum);
			break;
		}
	}
}

void writeOutput()
{
	printf("%lld\n", answ);
}

int main()
{	
	readInput();
	solve();
	writeOutput();
	return 0;
}