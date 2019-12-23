#include<iostream>
#include<algorithm>

using namespace std;
const long long N_max = 1000010;

struct change
{
    long long idx;
    long long h;
};

long long n, k, used[N_max];
long long a[N_max], minn = N_max + 1, sum = 0;
change b[N_max];

bool cmp(change c1, change c2)
{
    return c1.idx < c2.idx;
}

long long find_left(long long in, long long s)
{
    long long i = in - 1;
    while(i >= 0 && a[i] < s)
        i --;

    if (i < 0)
        return -1;
    return i;
}

long long find_right(long long in, long long s)
{
    long long i = in + 1;
    while(i < n && a[i] < s)
        i ++;

    if (i == n)
        return -1;
    return i;
}

long long find_sum()
{
    long long i = 1;
    long long maxx = 0, cnt = 0;
    while(i < n)
    {
        if (a[i] < a[i - 1])
        {
            i ++;
            continue;
        }

        if (a[i] >= a[maxx])
        {
            cnt = cnt + (i - maxx) * a[maxx];
            maxx = i;
        }
        i ++;
    }

    long long j = n - 1 , add = j;
    while(j > maxx)
    {
        if (a[j] > a[add])
            add = j;
        cnt = cnt + a[add];
        j --;
    }

    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (long long i = 0; i < n; i ++)
        cin >> a[i];

    cin >> k;
    for (long long i = 0; i < k; i ++)
        cin >> b[i].idx >> b[i].h;

    sort(b, b + k, cmp);

    for (long long i = 0; i < k; i ++)
    {
        used[i] = 1;
        a[b[i].idx] += b[i].h;
    }

    for (long long i = 0; i < k; i ++)
        if (used[i] == 1)
        {
            long long in = b[i].idx, c = b[i].h;
            long long l = find_left(in, a[in]);
            long long r = find_right(in, a[in]);
            if (l != -1 && r != -1)
            {
                used[i] = 0;
                a[in] -= c;
            }
        }



    long long ans = 0;
    for (long long i = 0; i < k; i ++)
        ans = ans + used[i];

    cout << ans << " ";
    long long sum = find_sum();
    cout << sum << endl;
    return 0;
}
/*
6
2 4 2 4 2 1
2
2 1
4 1
*/
