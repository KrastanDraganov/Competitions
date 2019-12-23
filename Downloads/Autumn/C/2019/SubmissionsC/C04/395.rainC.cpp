#include<iostream>
#include<algorithm>

using namespace std;
const int N_max = (1 << 20);

struct change
{
    int idx;
    long long h;
};

int n, k;
short used[N_max];
int  a[N_max], minn = N_max + 1, sum = 0;
change b[N_max];

bool cmp(change c1, change c2)
{
    return c1.idx < c2.idx;
}

int L[N_max], R[N_max];
long long find_sum()
{
    int i = 1;
    int maxx = 0;
    long long cnt = 0;
    while(i < n)
    {
        if (a[i] < a[i - 1])
        {
            i ++;
            continue;
        }

        if (a[i] >= a[maxx])
        {
            cnt = cnt + (long long)((long long)(i - maxx) * (long long)(a[maxx]));
            maxx = i;
        }
        i ++;
    }

    int j = n - 1, add = j;
    while(j > maxx)
    {
        if (a[j] > a[add])
            add = j;
        cnt = cnt + (long long)(a[add]);
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
    for (int i = 0; i < n; i ++)
        cin >> a[i];

    cin >> k;
    for (int i = 0; i < k; i ++)
        cin >> b[i].idx >> b[i].h;

    for (int i = 0; i < k; i ++)
    {
        used[i] = 1;
        a[b[i].idx] += b[i].h;
    }

    L[0] = a[0];
    for (int i = 1; i < n; i ++)
    {
        L[i] = L[i - 1];
        if (a[i] > L[i])
            L[i] = a[i];
    }
    for (int i = n - 1; i >= 0; i --)
    {
        R[i] = R[i + 1];
        if (a[i] > R[i])
            R[i] = a[i];
    }


    for (int i = 0; i < k; i ++)
        if (used[i] == 1)
        {
            int in = b[i].idx, c = b[i].h;
            int l = 0;
            if (in != 0)
                l = L[in - 1];
            int r = R[in + 1];
            if ((l >= a[in] && r >= a[in]) || b[i].h == 0)
            {
                used[i] = 0;
                a[in] -= c;
            }
        }



    int ans = 0;
    for (int i = 0; i < k; i ++)
        if (used[i] == 1)
            ans ++;

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
