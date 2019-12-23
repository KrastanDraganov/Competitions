#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string a[10010], p, s;
int n, m, k, e;

int L;

bool gen (string &s)
{
    int p = 0;
    int i = L-1;
    char stop = (char)(m+'a');
    do
    {
        do
        {
            char tmp = (char)(s[i]+p+1);
            if (tmp > stop)
            {
                p = 1;
                s[i] = 'a';
            }
            else s[i] = (char)(s[i]+1), p = 0;
    cout << s.find(s[i]) << "\t" << i << endl;
        }
        while (s.find(s[i]) == i-1);
        i--;
    }
    while (p && i >= 0);
    if (p) return 0;
    return 1;
}

bool sr(string a, string s)
{
    int c = a.size();
    int j = 0;
    for (int i = 0; i < c && j < L; i++)
    {
        //if (a.find(s[i]) == string::npos) return 0;
        if (a[i] == s[j]) j++;
    }
    if (j != L) return 0;
    return 1;
}

set <string> st;

int br = 0, maxbr = 0;

int main ()
{
    /// GENERIRA POVTAR{SHTI BUKVI

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    L = k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++)
    {
        s += (char)(i+'a');
    }

    do
    {
        br = 0;

        for (int i = 0; i < n; i++)
        {
            if (sr(a[i], s))
            {
                br++;
            }
        }
        if (br == maxbr) st.insert(s);
                if (br > maxbr)
                {
                    st.clear();
                    st.insert(s);
                    maxbr = br;
                    p = s;
                }
       //cout << s << '\t' << br << endl;
       cout << endl << "========================================\n\n";
    }
    while (gen(s));

    if (maxbr) cout << maxbr << endl << p << endl << st.size() << endl;
    else    cout << 0 << endl;

    return 0;
}
/**
5 7 2
fagcbdaga
dcdfb
acfebdc
cfc
cegdb
*/
