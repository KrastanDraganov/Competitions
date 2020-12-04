#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3,MAXL=30;
int teleport[MAXN][MAXL];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;

    for(int currv=0;currv<n;++currv){
        int nextv;
        cin>>nextv;
        --nextv;
        teleport[currv][0]=nextv;
    }

    for(int i=1;i<MAXL;++i){
        for(int currv=0;currv<n;++currv){
            teleport[currv][i]=teleport[teleport[currv][i-1]][i-1];
        }
    }

    while(q--){
        int startv,steps;
        cin>>startv>>steps;

        int endv=startv-1;
        for(int i=MAXL-1;i>=0;--i){
            if((1<<i) & steps){
                endv=teleport[endv][i];
            }
        }

        cout<<endv+1<<endl;
    }
return 0;
}