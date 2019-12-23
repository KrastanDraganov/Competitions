#include<iostream>
#include<algorithm>

using namespace std;
const short N_max = (1 << 14);

struct change
{
    short idx;
    short h;
};

int n, k;
short used[N_max], t[2 * N_max];
short a[N_max], minn = N_max + 1, sum = 0;
change b[N_max];

bool cmp(change c1, change c2)
{
    return c1.idx < c2.idx;
}

short make_tree(short root, int l, int r)
{
    if (l == r)
        return (t[root] = a[l]);

    int m = (l + r) / 2;
    return (t[root] = max(make_tree(root * 2, l, m),
                          make_tree(root * 2 + 1, m + 1, r)));
}

short find_max(short root, short l, short r, short ql, short qr)
{
    if (l == ql && r == qr)
        return (t[root]);

    short m = (l + r) / 2;
    if (qr <= m)
        return find_max(root * 2, l, m, ql, qr);
    if (ql > m)
        return find_max(root * 2 + 1, m + 1, r, ql, qr);

    return max(find_max(root * 2, l, m, ql, m),
               find_max(root * 2 + 1, m + 1, r, m + 1, qr));
}

void update(short root, short l, short r, short in)
{
    if (l == r)
    {
        t[root] = a[in];
        return;
    }

    short m = (l + r) / 2;
    if (in <= m)
        update(root * 2, l, m, in);
    if (in > m)
        update(root * 2 + 1, m + 1, r, in);

    t[root] = max(t[root * 2], t[root * 2 + 1]);
}
short find_sum()
{
    int i = 1;
    short maxx = 0, cnt = 0;
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

    int j = n - 1, add = j;
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
    for (int i = 0; i < n; i ++)
        cin >> a[i];

    cin >> k;
    for (int i = 0; i < k; i ++)
        cin >> b[i].idx >> b[i].h;

    sort(b, b + k, cmp);

    for (int i = 0; i < k; i ++)
    {
        used[i] = 1;
        a[b[i].idx] += b[i].h;
    }

    make_tree(1, 0, n - 1);

    for (int i = 0; i < k; i ++)
        if (used[i] == 1)
        {
            int in = b[i].idx;
            short c = b[i].h;
            short l = 0;
            if (in != 0)
                l = find_max(1, 0, n - 1, 0, in - 1);
            short r = 0;
            if (in != n - 1)
                r = find_max(1, 0, n - 1, in + 1, n - 1);
            if (l >= a[in] && r >= a[in])
            {
                used[i] = 0;
                a[in] -= c;
                update(1, 0, n - 1, in);
            }
        }



    short ans = 0;
    for (int i = 0; i < k; i ++)
        ans = ans + used[i];

    cout << ans << " ";
    short sum = find_sum();
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
