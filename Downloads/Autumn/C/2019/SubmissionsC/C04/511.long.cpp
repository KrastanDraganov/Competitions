#include<iostream>

using namespace std;
const int N_max = 100010;

int n, m, k;
string w[N_max];
int p[10000], used[10000], max_cnt, all;
string str;

bool cmp(string &s1, string &s2)
{
    for (int i = 0; i < k; i ++)
    {
        if (s1[i] > s2[i])
            return true;
        if (s2[i] < s2[i])
            return false;
    }
    return false;
}
void check()
{
    int cnt = 0;
    for (int i = 0; i < n; i ++)
    {
        int j = 0, idx = 1, sz = w[i].size();
        while(j < sz && idx <= k)
        {
            while(j < sz && w[i][j] != (char)(p[idx] + 'a'))
                j ++;

            if (j != sz)
                idx ++;

            j ++;
        }

        if (idx > k)
            cnt ++;
    }

    string rep = "";
    for (int i = 1; i <= k; i ++)
        rep = rep + (char)(p[i] + 'a');

    if (cnt > max_cnt)
    {
        max_cnt = cnt;
        str = rep;
        all = 1;
    }
    else
    if (cnt == max_cnt)
    {
        all ++;
        if (cnt != 0 && cmp(str, rep))
            str = rep;
    }
}

void gen(int pos)
{
    if (pos == k + 1)
        check();
    else
    {
        for (int i = 0; i < m; i ++)
        {
            if (used[i] == 0)
            {
                used[i] = 1;
                p[pos] = i;
                gen(pos + 1);
                used[i] = 0;
            }
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

    if (m < k)
    {
        cout << "0" << endl;
        return 0;
    }
    gen(1);

    if (max_cnt == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    cout << max_cnt << endl;
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
