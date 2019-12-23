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

long long getCurrentForDays(long long days)
{
	int i;
	long long result = 0;
	for (i = 0; i < n; i++)
	{
		if (current[i] + days > max[i])
		{
			result += max[i];
		}
		else
		{
			result += current[i] + days;
		}
	}
	
	return result;
}

void solve()
{
	long long i, left, right, mid, currentSum;
	
	left = 0;
	right = 0;
	for (i = 0; i < n; i++)
	{
		if (max[i] - current[i] > right)
		{
			right = max[i] - current[i];
		}
	}
	
	while (1 > 0)
	{
		//printf("%ld %ld\n", left, right);
		if (left == right)
		{
			answ = left;
			return;
		}
		else if (left == right - 1)
		{
			if (getCurrentForDays(left) >= m)
			{
				answ = left;
			}
			else
			{
				answ = right;
			}
			
			return;
		}
	
		mid = (left + right) / 2;
		currentSum = getCurrentForDays(mid);
		//printf("mid: %ld, current: %ld\n", mid, currentSum);
		if (currentSum < m)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
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