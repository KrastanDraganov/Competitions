#include<bits/stdc++.h>
using namespace std;
int table[3005][3005];
bool j[3005][3005];
enum Dir{LEFT,RIGHT,UP,DOWN};
pair<int,int> dirs[]={{0,-1},{0,1},{-1,0},{1,0}};
int getX(int x,Dir dir){
    return x+dirs[dir].first;
}
int getY(int y,Dir dir){
    return y+dirs[dir].second;
}
vector<pair<int,int>>points[900005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k,a,b,br=0;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        table[a][b]=1;
        points[0].push_back({a,b});
        if(!j[a][b]) br++;
        j[a][b]=true;
    }
    long long rez=0,i3=1;
    br=n*m-br;
    while(br>0){
        int br2=0;
        //cout<<br<<endl;
        for(int i=0;i<points[i3-1].size();i++){
            int x=points[i3-1][i].first,y=points[i3-1][i].second;
            for(auto dir:{LEFT,RIGHT,UP,DOWN}){
                int cx=getX(x,dir),cy=getY(y,dir);
                if(cx>0 and cy>0 and cx<=n and cy<=m)
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