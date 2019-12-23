#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string a[10002];
bool found(string s, char sym)
{
    for (int i=0; i<s.size(); i++) if (s[i]==sym) return true;
    return false;
}

bool itis (string s, string s2)
{
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=s2[0]) s2=s2.substr(1, s2.size()-1);
        if (s2.empty()) return true;
    }
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
    else if (K<4)
    {
        sort(a, a+N);
        int maxi=0;
        string str="";
        for (int i=0; i<N-maxi; i++)
        {
            for (int l=0; l<N-K; l++)
            {
                int br=0;
                string fnd;
                fnd=a[i].substr(l, K);
                for (int j=j+1; j<N; j++) if (itis(a[j], fnd)) br++;
                if (br>maxi) maxi=br, str=fnd;
                if (maxi==N) break;
            }
        }
        cout << maxi << endl;
    }
    else cout << 0 << endl;
    return 0;
}
