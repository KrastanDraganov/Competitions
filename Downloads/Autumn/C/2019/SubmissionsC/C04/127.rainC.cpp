#include<iostream>
#include<algorithm>

using namespace std;
const int N_max = 1000010;

struct change
{
    int idx, h;
};

bool cmp(change a, change b)
{
    return a.idx < b.idx;
}


int n, a[N_max], k, used[N_max];
change b[N_max];

int find_left(int in, int s)
{
    int i = in - 1;
    while(i >= 0 && a[i] < s)
        i --;

    if (i < 0)
        return -1;
    return i;
}

int find_right(int in, int s)
{
    int i = in + 1;
    while(i < n && a[i] < s)
        i ++;

    if (i == n)
        return -1;
    return i;
}

int find_ans()
{
    int i = 1, maxx = 0, cnt = 0;
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

    int j = maxx + 1;
    while(j < n)
    {
        cnt = cnt + a[j];
        j ++;
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

    int k;
    cin >> k;
    for (int i = 0; i < k; i ++)
        cin >> b[i].idx >> b[i].h;

    sort(b, b + k, cmp);

    int cnt = 0;
    for (int i = 0; i < k; i ++)
    {
        int in = b[i].idx, c = b[i].h;
        int l = find_left(in, a[in] + c);
        int r = find_right(in, a[in] + c);

        if ((l == -1 && r == -1) || (l != -1 && r != -1))
            continue;

        if (l != -1)
            used[i] = -1;
        else
            used[i] = 1;

        for (int j = 0; j < i; j ++)
            if (used[j] == -1 && a[in] + c >= a[b[j].idx] + b[j].h)
                used[j] = 0;
        cnt ++;
    }

    cout << cnt << " ";
    for (int i = 0; i < k; i ++)
        if (used[i] != 0)
        a[b[i].idx] += b[i].h;

    int ans = find_ans();
    cout << ans << endl;

    /*for (int i = 0; i < k; i ++)
        for (int j = i + 1; j < k; j ++)
        {
            int r = find_right(b[i].idx, a[b[i].idx] + b[i].h);
            int l = find_left(b[j].idx, a[b[j].idx] + b[j].h)
        }*/
    return 0;
}
/*
6
2 4 2 4 2 1
2
2 1
4 1
*/
