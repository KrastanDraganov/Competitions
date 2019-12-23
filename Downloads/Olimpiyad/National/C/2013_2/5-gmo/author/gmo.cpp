#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 100
using namespace std;

int n;
int startPosition, endPosition;
vector<int> objects;
double memo[MAXN][MAXN];

double solve(int fromIndex, int toIndex, double speed)
{
    if (objects[fromIndex]==endPosition) return 0;
    if (objects[toIndex]==endPosition) return abs(objects[fromIndex]-objects[toIndex])/speed;
    if (memo[fromIndex][toIndex]!=-1) return memo[fromIndex][toIndex];

    double solution = 1000000000;
	if (0 < fromIndex && fromIndex <= toIndex)
	{
		solution = min(solution,
                 (objects[fromIndex] - objects[fromIndex-1]) / speed
                 + solve(fromIndex-1, toIndex, speed*2));
	}

    if (fromIndex <= toIndex && toIndex < n - 1)
	{
		solution = min(solution,
                 (objects[toIndex+1] - objects[fromIndex]) / speed
                 + solve(toIndex+1, fromIndex, speed*2));
	}

	if (0 < toIndex && toIndex < fromIndex)
	{
		solution = min(solution,
                 (objects[fromIndex] - objects[toIndex-1]) / speed
                 + solve(toIndex-1, fromIndex, speed*2));
	}

	if (toIndex < fromIndex && fromIndex < n - 1)
	{
		solution = min(solution,
                 (objects[fromIndex+1] - objects[fromIndex]) / speed
                 + solve(fromIndex+1, toIndex, speed*2));
	}

    memo[fromIndex][toIndex] = solution;
    return solution;
}

void input()
{
    int carrots;
    cin >> startPosition >> endPosition;
    cin >> carrots;
    for(int i = 0; i < carrots; i++)
    {
        int carrotPosition;
        cin >> carrotPosition;
        objects.push_back(carrotPosition);
    }
    n = carrots;
}

void initializeData()
{
    objects.push_back(startPosition);
    objects.push_back(endPosition);
    n += 2;
    sort(objects.begin(), objects.end());
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            memo[i][j] = -1;
        }
    }
}

int main()
{
    input();
    initializeData();

    // solve
    int startIndex = 0;
    for(int i = 0; i < n; i++)
    {
        if (objects[i] == startPosition)
        {
            startIndex = i;
            break;
        }
    }
    double answer = solve(startIndex, startIndex, 1);

    // output
    printf("%.9f\n", answer);
    // cout << setiosflags(ios::fixed) << setprecision(9);
    // cout << answer << endl;
}
