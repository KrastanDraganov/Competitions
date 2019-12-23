#include <cstdio>
#include <algorithm>

using namespace std;

struct pair_numbers
{
    int x;
    int y;
};

int ans[4], used[4], current[4], sz, cnt, max_diff = 4 * 100000;;
pair_numbers all_numbers[524288];

void read()
{
    int i, j, n, number;
    for (i = 0; i < 4; i++)
    {
        scanf ("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf ("%d", &number);
            all_numbers[sz].x = number;
            all_numbers[sz++].y = i;
        }
    }
}

int cmp(pair_numbers a, pair_numbers b)
{
    if (a.x < b.x) return 1;
    return 0;
}

void solve()
{
    int first, last, i;

    sort(all_numbers, all_numbers + sz, cmp);

    first = last = 0;
    current[all_numbers[first].y] = all_numbers[first].x;
    used[all_numbers[first].y] = 1;
    cnt++;

    while(first < sz)
    {
        if (cnt == 4)
        {
            if (all_numbers[first].x - all_numbers[last].x < max_diff)
            {
                max_diff = all_numbers[first].x - all_numbers[last].x;
                for (i = 0; i < 4; i++)
                {
                    ans[i] = current[i];
                }
            }
            used[all_numbers[last].y]--;
            if (used[all_numbers[last].y] == 0)
            {
                current[all_numbers[last].y] = 0;
                cnt--;
            }
            last++;
        }
        else
        {
            first++;
            if (used[all_numbers[first].y] == 0)
            {
                cnt++;
            }
            used[all_numbers[first].y]++;
            current[all_numbers[first].y] = all_numbers[first].x;
        }
    }
    printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
}

int main()
{
    read();
    solve();

    return 0;
}
