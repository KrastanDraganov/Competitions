#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string a[10002];
bool found(string s, char sym)
{
    for (int i=0; i<s.size(); i++) if (s[i]==sym) return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    for (int i=0; i<N; i++) cin >> a[i];
    if (K==1)
    {
        int maxi=0;
        char maxsym='z'+1;
        for (int i=0; i<M; i++)
        {
            char sym='a'+i;
            int br=0;
            for (int j=0; j<N; j++)
            {
                if (found(a[j], sym))br++;
            }
            if (br>maxi) maxi=br, maxsym=sym;
        }
        if (maxi) cout << maxi << endl << maxsym << endl << 1 << endl;
        else cout << 0 << endl;
    }
    else cout << 0 << endl;
    return 0;
}
