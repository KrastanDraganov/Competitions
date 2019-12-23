#include<iostream>
#include<map>

using namespace std;

map<char,int> br;
bool used[1000];

int main()
{
    int n,m,k,maxx = 0;
    cin>>n>>m>>k;

    char maxch;

    for(int i = 0;i < n;i++)
    {
        string a;
        cin>>a;

        for(int j = 0;j < a.size();j++)
        {
            if(used[a[j]] == false)
            {
                br[a[j]]++;
                used[a[j]] = true;
            }
        }

        for(int j = 0;j < a.size();j++)
        {
            used[a[j]] = false;
        }
    }

    int br2 = 0;

    for(int i = 'a';i <= 'z';i++)
    {
        if(br[char(i)] > maxx)
        {
            maxx = br[char(i)];
            maxch = char(i);
            br2 = 0;
        }

        if(br[char(i)] == maxx)
        {
            br2++;
        }
    }
    cout<<maxx<<endl;
    cout<<maxch<<endl;
    cout<<br2<<endl;
}
