#include<iostream>

using namespace std;
const int N_max = 10010;

int n, m, k, used[28], ans, all;
string w[N_max];
string str, add;

void check()
{
    int cnt = 0;
    for (int i = 0; i < n; i ++)
    {
        int sz = w[i].size();
        int j = 0, idx = 0;
        while(j < sz && idx < k)
        {
            while(j < sz && w[i][j] != add[idx])
                j ++;

            if (j != sz)
                idx ++;
            j ++;
        }

        if (idx == k)
            cnt ++;
    }



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
    if (pos == k)
        check();
    else
    {
        for (int i = 0; i < m; i ++)
            if (!used[i])
            {
                add[pos] = (char)(i + 'a');
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

    for (int i = 0; i < k; i ++)
        add = add + "a";

    gen(0);

    if (ans == 0)
    {
        cout << "0" << endl;
        return 0;
    }
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

/*
3 7 4
baddceabdeab
aabdddecddeede
acedeb
*/
