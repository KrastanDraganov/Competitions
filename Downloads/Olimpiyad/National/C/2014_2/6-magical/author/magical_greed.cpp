#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int magic = 1000;
const int inf = 1000 * 1000 * 1000;

vector <pair <int, int> > wear;
int ans[4], last[4], c, len[4];

int main()
{
    int i, j, k, best, sum, cnt;

    for (i = 0; i < 4; i++)
    {
        scanf("%d", &len[i]);
        for (j = 0; j < len[i]; j++)
        {
            scanf("%d", &c);
            wear.push_back(make_pair(c, i));
        }
    }

    sort(wear.begin(), wear.end());
    sum = wear.size();
    best = inf;
    for (i = 0; i < sum; i++)
    {
        for (j = 0; j < 4; j++)
            last[j] = -1;
        cnt = 0;
        for (j = i; j < sum; j++)
        {
            if (j - i > magic)
                break;
            if (last[wear[j].second] == -1)
            {
                last[wear[j].second] = wear[j].first;
                cnt++;
            }
            if (cnt == 4)
            {
                if (best > wear[j].first - wear[i].first)
                {
                    best = wear[j].first - wear[i].first;
                    for (k = 0; k < 4; k++)
                        ans[k] = last[k];
                }
                break;
            }
        }
    }
    printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
    return 0;
}
