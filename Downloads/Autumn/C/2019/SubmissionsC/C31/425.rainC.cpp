#include <iostream>
using namespace std;
struct K
{
    int h, ind, pok, udachen;
    bool moje;
};
int n, k, brpr=0,  s=0;
K p[1000002];
void read()
{
    cin >> n;
    for (int i=0; i<n; i++){cin >> p[i].h;p[i].moje=false; p[i].ind=i; p[i].udachen=p[i].pok=-1;}
    cin >> k;
    for (int i=0; i<k; i++)
    {
        int u, v;
        cin >> u >> v;
        p[u].moje=true;
        p[u].udachen=1;
        p[u].pok=v;
    }
    for (int i=1; i<n-1; i++)
    {
        if (p[i].moje=false)continue;
        if (p[i].h<p[i-1].h && p[i].h<p[i+1].h){p[i].udachen=0;}
      //  cout << endl << p[i].udachen << "za i=" << i << endl;
    }
}
int area()
{
    int sum=0;
    for (int i=1; i<n-1; i++)
    {
      //  cout << p[i].udachen << "za i=" << i << endl;
        if (p[i].udachen==0)goto here;
        if (p[i-1].udachen==0)
        {

            int y;
            {
                for (int j=i-1; j>=0; j--)if (p[j].h>=p[i].h){y=j; break;}
            }
            if (p[i].h>p[y].h)
            {
                sum+=min(p[y].h,p[i].h)*(i-y);
            }
            if (p[i].h<p[y].h)
            {
                sum+=min(p[y].h,p[i].h)*(i-y);
            }
            if (p[i].h==p[y].h)sum+=((i-y)*p[i].h);
        }
        if (p[i].h>p[i-1].h)sum+=p[i-1].h;
        if (p[i].h<p[i-1].h)sum+=p[i].h;
        if (p[i].h==p[i-1].h)sum+=p[i].h;
        here: ;
    }
   // cout << endl << sum << endl;
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read();
    int s=area();
    cout << endl;

    for (int i=0; i<n; i++)
    {
        if (p[i].moje==false)continue;
        if (p[i].moje==true)
        {
            if (p[i].udachen==1){p[i].h+=p[i].pok;s+=p[i].pok;brpr++;}
        }
    }
    cout << brpr+1 << " " << s << endl;
    return 0;
}
/*
6
2 4 2 4 2 1
2
2 1
4 1
*/
