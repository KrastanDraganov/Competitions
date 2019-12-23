#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000000

long a[MAXN];
int n;
long sum;

void readInput()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%ld", &a[i]);
	}
}

void greedy()
{
	int i;
	sum = 0;
	
	while (1 > 0)
	{
		int flag = 0;
		for (i = 1; i < n; i++)
		{
			if (a[i] != a[i-1])
			{
				flag = 1;
				break;
			}
		}
		
		if (flag == 0)
		{
			break;
		}
		
		long max = a[0];
		int j = 0;
		
		for (i = 1; i < n; i++)
		{
			if (a[i] > a[j])
			{
				max = a[i];
				j = i;
			}
		}
		
		for (i = 0; i < n; i++)
		{
			if (i != j)
			{
				a[i]++;
			}
		}
		
		sum++;
	}
	
	printf("%ld\n", sum);
}

int main()
{
	readInput();
	greedy();
	return 0;
}