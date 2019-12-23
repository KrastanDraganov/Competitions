/*
*	Solution using a (modular) backpack
* 	Complexity O(c*n),... memory complexity is O(c) by saving only the last 2 rows 
*   if you are lucky might be much less than O(c*n) (because we stop when a solution is found), order of numbers has an impact on the complexity
*   random_shuffle in the beginning might help you. 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int c, n;
int a[100100];
bool dp[2][100100];  // this is for the backpack
int pprev[100100];   // pprev[k] stores the index of the element who first made dp[*][k] true

void printResult(int pos, bool printedFirst)
{
	if(pos == 0 && printedFirst)
		return;

	printResult((pos - a[pprev[pos]] + c)%c, true);
	if(pos == 0)
		printf("%d\n", pprev[pos]);
	else
		printf("%d ", pprev[pos]);
}
int main ()
{
	memset(pprev, 0, sizeof(pprev));
	memset(dp, 0, sizeof(dp));
	
	scanf ("%d%d", &c, &n);
	int now = 0, i, j;
	for(i = 1; i <= n; i ++)
	{
		scanf ("%d", &a[i]);
		a[i] %= c; 

		if (a[i] == 0)
		{
			printf("%d\n", i);
			return 0;
		}

		for (j = 0; j < c; j ++)
		{
			dp[now][j] = 0;
			if(dp[!now][j])
				dp[now][j] = 1; // if we can make a mod sum of 0 without this element, we're happy with it! 
			else
				if(dp[!now][(j - a[i] + c)%c])
				{
					dp[now][j] = 1; // we can make this mode by using the current number! yay
					pprev[j] = i;	// we care only for the first number that makes a new mod
				}
		}

		if(dp[now][a[i]] == 0)
			{
				dp[now][a[i]] = 1;	
				pprev[a[i]] = i;
			}
		
		if(dp[now][0])
		{
			printResult(0, false);
			break;
		}
		now = !now;
	}

	return 0;
}