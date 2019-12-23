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

int compare(const void * a, const void * b)
{
  return (*(long*)a - *(long*)b);
}

void solve()
{
	qsort(a, n, sizeof(long), compare);
	
	sum = 0;	
	int i = 0;
	while ((i + 1 < n) && (a[i+1] == a[i]))
	{
		i++;
	}
	
	if ((i == n-1) && (a[i] == a[i-1]))
	{
		return;
	}
	
	i++;
	long prev = 0;
	while (i < n)
	{
		long diff = (a[i] - a[i-1]) + prev;
		long count = 1;
		int j = i + 1;
		while ((j + 1 < n) && (a[j] == a[i]))
		{
			count++;
			j++;
		}

		sum = sum + diff * count;
		i += count;
		prev = diff;
	}
	
	printf("%ld\n", sum);
}

int main()
{
	readInput();
	solve();
	return 0;
}