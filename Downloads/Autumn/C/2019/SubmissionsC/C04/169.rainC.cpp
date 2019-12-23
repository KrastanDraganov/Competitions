#include<iostream>

using namespace std;
const int N_max = 1000010;

struct change
{
    int idx, h;
};

int n, a[N_max], k, used[N_max], minn = N_max + 1, sum = 0;
change b[N_max];

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

void check()
{
    int cnt = 0;
    for (int i = 0; i < k; i ++)
        if (used[i] == 1)
        a[b[i].idx] += b[i].h, cnt ++;

    if (cnt < minn)
    {
        int tek = find_ans();
        if (tek > sum || (tek == sum && cnt < minn))
        {
            minn = cnt;
            sum = tek;
        }
    }
    for (int i = 0; i < k; i ++)
        if (used[i] == 1)
        a[b[i].idx] -= b[i].h;
}
void gen(int pos)
{
    if (pos == k)
        check();
    else
    {
        used[pos] = 1;
        gen(pos + 1);
        used[pos] = 0;
        gen(pos + 1);
    }
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

    gen(0);

    cout << minn << " " << sum << endl;
    return 0;
}
/*
6
2 4 2 4 2 1
2
2 1
4 1
*/
