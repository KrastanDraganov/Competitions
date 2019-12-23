#include<bits/stdc++.h>
#define endl '\n'
#define MAXN 3005
using namespace std;
bool used[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,startx=INT_MAX,endx=-1,starty=INT_MAX,endy=-1;
    cin>>n;
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1<startx) startx=x1;
        if(x2>endx) endx=x2;
        if(y1<starty) starty=y1;
        if(y2>endy) endy=y2;
        for(int i2=y1;i2<y2;i2++){
            for(int i3=x1;i3<x2;i3++){
                used[i2][i3]=true;
            }
        }
    }
    int result=0;
    for(int i=starty;i<endy;i++){
        for(int i2=startx;i2<endx;i2++){
            if(used[i][i2]){
                result++;
            }
        }
    }
    cout<<result<<endl;
return 0;
}