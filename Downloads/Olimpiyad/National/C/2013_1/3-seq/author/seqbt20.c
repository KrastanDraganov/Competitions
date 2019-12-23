#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000000

long a[MAXN];
int n;
long sum, current;

void readInput()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%ld", &a[i]);
	}
}

#define MAXDEPTH 1000

void go()
{
	if ((current > MAXDEPTH) || (sum == current))
	{
		return;
	}

	int i, j, min, mini, flag;
	
	flag = 0;
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
		sum = current;
		return;
	}
	
	mini = 0;
	min = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[mini] > a[i])
		{
			mini = i;
			min = a[i];
		}
	}
	
	for (i = 0; i < n; i++)
	{
		if (a[i] != min)
		{
			for (j = 0; j < n; j++)
			{
				if (j != i)
				{
					a[j]++;
				}
			}
			current++;
			go();
			current--;
			for (j = 0; j < n; j++)
			{
				if (j != i)
				{
					a[j]--;
				}
			}
		}
	}
}

void solve()
{
	sum = 1000000000;
	current = 0;
	go();
	printf("%d\n", sum);
}

int main()
{
	readInput();
	solve();
	return 0;
}