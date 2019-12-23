#include<iostream>

using namespace std;
const int N_max = 10010;

int n, m, k, used[27], ans, all;
char p[15];
string w[N_max];
string str;

void check()
{
    int cnt = 0;
    for (int i = 0; i < n; i ++)
    {
        int sz = w[i].size();
        int j = 0, idx = 1;
        while(j < sz && idx <= k)
        {
            while(j < sz && w[i][j] != p[idx])
                j ++;

            if (j != sz)
                idx ++;
            j ++;
        }

        if (idx > k)
            cnt ++;
    }

    string add = "";
    for (int i = 1; i <= k; i ++)
        add = add + p[i];

    if (cnt > ans)
    {
        ans = cnt;
        str = add;
        all = 1;
        return;
    }

    if (cnt == ans)
    {
        all ++;
        if (add < str)
            str = add;
    }

}
void gen(int pos)
{
    if (pos == k + 1)
        check();
    else
    {
        for (int i = 0; i < m; i ++)
            if (!used[i])
            {
                p[pos] = (char)(i + 'a');
                used[i] = 1;
                gen(pos + 1);
                used[i] = 0;
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i ++)
        cin >> w[i];

    if (k > m)
    {
        cout << "0" << endl;
        return 0;
    }

    gen(1);

    cout << ans << endl;
    cout << str << endl;
    cout << all << endl;
    return 0;
}
/*
5 7 2
fagcbdaga
dcdfb
acfebdc
cfc
cegdb
*/
