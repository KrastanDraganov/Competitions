#include <iostream>
using namespace std;
struct K
{
    int h, ind, pok;
    bool udachen, moje;
};
int n, k, brpr=0,  s=0;
K p[1000002];
void read()
{
    cin >> n;
    for (int i=0; i<n; i++){cin >> p[i].h;p[i].moje=false; p[i].ind=i;}
    /*for (int i=0; i<n; i++)
    {
        cout << s << "+" << p[i].h << "=";
        s+=p[i].h;
        cout << s << endl;
    }*/
    cin >> k;
    for (int i=0; i<k; i++)
    {
        int u, v;
        cin >> u >> v;
        p[u].moje=true;
        p[u].udachen=true;
        p[u].pok=v;
    }
    for (int i=1; i<n-2; i++)
    {
        if (p[i].moje=false)continue;
        if (p[i].h<p[i-1].h && p[i].h<p[i+1].h){p[i].udachen=false; s-=p[i].h;}
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read();
    for (int i=0; i<n; i++)
    {
        if (p[i].moje==false)continue;
        if (p[i].moje==true)
        {
            if (p[i].udachen==true)p[i].h+=p[i].pok;
            s+=p[i].pok;
            brpr++;
        }
    }
    cout << brpr << " " << s << endl;
    return 0;
}
/*
6
2 4 2 4 2 1
2
2 1
4 1
*/
