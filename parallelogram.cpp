#include<iostream>
#include<vector>
#include<utility>

using namespace std;

const int MAXN=28;
char table[MAXN][MAXN];
vector<pair<int,int>> cords;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            cin>>table[i][i2];
            if(table[i][i2]=='x'){
                cords.push_back({i,i2});
            }
        }
    }

    int res=0;
    for(int i=0;i<cords.size()-2;++i){
        for(int i2=i+1;i2<cords.size()-1;++i2){
            for(int i3=i2+1;i3<cords.size();++i3){
                int nextx=cords[i3].first+cords[i].first-cords[i2].first;
                int nexty=cords[i3].second+cords[i].second-cords[i2].second;
                if(nextx>=0 and nextx<n and nexty>=0 and nexty<m){
                    int area=(cords[i3].second-cords[i2].second)*(cords[i].first-cords[i2].first)
                            -(cords[i].second-cords[i2].second)*(cords[i3].first-cords[i2].first);
                    if(table[nextx][nexty]=='x' and area!=0){
                        ++res;
                    }
                }
            }
        }
    }
    res/=2;
    cout<<res<<endl;
return 0;
}