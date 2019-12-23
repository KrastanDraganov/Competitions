#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct str
{
    int len, bpr, baf;
    str (int n1, int n2, int n3)
    {
        len=n1;
        bpr=n2;
        baf=n3;
    }
};
vector <str> a;
struct bigger
{
    int ind;
    int l;
};
bigger b[1000002];
bool cmp(bigger a, bigger b)
{
    return a.ind<b.ind;
}
int N, K;
int maxw=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i=0; i<N; i++)
    {
        int num;
        cin >> num;
        a.push_back(str(num, 0, 0));
    }
    cin >> K;
    for (int i=0; i<K; i++)
    {
        cin >> b[i].ind >> b[i].l;
    }
    sort (b, b+K, cmp);
    int br=K;
    int brr=0;
    for (int i=0; i<N; i++)
    {
        a[i].bpr=brr;
        if (a[i].len>brr) brr=a[i].len;
    }
    brr=0;
    for (int i=N-1; i>=0; i--)
    {
        a[i].baf=brr;
        if (a[i].len>brr) brr=a[i].len;
    }
    int bpr2=0, baf2=0;
    for (int i=0; i<K; i++)
    {
        if (a[b[i].ind].len+b[i].l<=a[b[i].ind].bpr && a[b[i].ind].len+b[i].l<=a[b[i].ind].baf) b[i].ind=-1, br--;
        else a[b[i].ind].len+=b[i].l;
    }
    brr=0;
    for (int i=0; i<N; i++)
    {
        a[i].bpr=brr;
        if (a[i].len>brr) brr=a[i].len;
    }
    brr=0;
    for (int i=N-1; i>=0; i--)
    {
        a[i].baf=brr;
        if (a[i].len>brr) brr=a[i].len;
    }
    for (int i=0; i<N-1; i++) maxw+=(min(a[i+1].bpr, a[i].baf));
    cout << br << " " << maxw << endl;
    return 0;
}
