#include<bits/stdc++.h>
using namespace std;
int table[1005][1005];
enum Dir{LEFT,RIGHT,UP,DOWN};
pair<int,int> dirs[]={{0,-1},{0,1},{-1,0},{1,0}};
int getX(int x,Dir dir){
    return x+dirs[dir].first;
}
int getY(int y,Dir dir){
    return y+dirs[dir].second;
}
vector<pair<int,int>>points[100005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,br=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int i2=0;i2<m;i2++){
            //cout<<i<<" "<<i2<<endl;
            cin>>table[i][i2];
            if(table[i][i2]==0) br++;
            if(table[i][i2]==1) points[0].push_back({i,i2});
        }
    }
    int rez=0,i3=1;
    while(br>0){
        int br2=0;
        //cout<<br<<endl;
        for(int i=0;i<points[i3-1].size();i++){
            int x=points[i3-1][i].first,y=points[i3-1][i].second;
            for(auto dir:{LEFT,RIGHT,UP,DOWN}){
                int cx=getX(x,dir),cy=getY(y,dir);
                if(cx>-1 and cy>-1 and cx<n and cy<m)
                if(table[cx][cy]==0){
                    //cout<<x<<" "<<y<<" "<<cx<<" "<<cy<<endl;
                    br2++;
                    table[cx][cy]=1;
                    points[i3].push_back({cx,cy});
                }
            }
        }
        rez++;
        i3++;
        br-=br2;
    }
    cout<<rez<<endl;
return 0;
}
