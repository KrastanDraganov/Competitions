#include<iostream>
#include<algorithm>

using namespace std;
const int N_max = (1 << 15);

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

long long L[N_max], R[N_max];
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

    long long j = n - 1, add = n - 1;
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

    L[0] = a[0];
    for (long long i = 1; i < n; i ++)
    {
        L[i] = L[i - 1];
        if (a[i] > L[i])
            L[i] = a[i];
    }
    for (long long i = n - 1; i >= 0; i --)
    {
        R[i] = R[i + 1];
        if (a[i] > R[i])
            R[i] = a[i];
    }


    for (long long i = 0; i < k; i ++)
        if (used[i] == 1)
        {
            long long in = b[i].idx, c = b[i].h;
            long long l = -1;
            if (in != 0)
                l = L[in - 1];
            long long r = R[in + 1];
            if (l >= a[in] && r >= a[in])
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
