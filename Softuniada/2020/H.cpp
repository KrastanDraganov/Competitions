#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;
const int MAXN=7e6+3;
vector<pair<int,int>> sticks;
bool used[2][MAXN];
void print_stick(pair<int,int> stick){
    cout<<"|"<<stick.first<<"-"<<stick.second<<"|";
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        sticks.push_back({10*x+y,i});
        if(x!=y){
            sticks.push_back({10*y+x,i});
        }
    }
    sort(sticks.begin(),sticks.end());
    int all=0;
    for(int i=0;i<sticks.size();++i){
        int code=sticks[i].first;
        for(int i2=0;i2<sticks.size();++i2){
            if(i2==i or sticks[i2].second==sticks[i].second){
                continue;
            }
            int code2=code*100+10*sticks[i2].first.first+sticks[i2].first.second;
            for(int i3=0;i3<sticks.size();++i3){
                int code3=code2*100+10*sticks[i3].first.first+sticks[i3].first.second;
                if(used[0][code3] or i3==i or i3==i2 or sticks[i3].second==sticks[i].second or sticks[i2].second==sticks[i3].second){
                    continue;
                }
                used[0][code3]=true;
                ++all;
            }
        }
    }
    cout<<all<<endl;
    for(int i=0;i<sticks.size();++i){
        int code=10*sticks[i].first.first+sticks[i].first.second;
        for(int i2=0;i2<sticks.size();++i2){
            if(i2==i or sticks[i2].second==sticks[i].second){
                continue;
            }
            int code2=code*100+10*sticks[i2].first.first+sticks[i2].first.second;
            for(int i3=0;i3<sticks.size();++i3){
                int code3=code2*100+10*sticks[i3].first.first+sticks[i3].first.second;
                if(used[1][code3] or i3==i or i3==i2 or sticks[i3].second==sticks[i].second or sticks[i2].second==sticks[i3].second){
                    continue;
                }
                used[1][code3]=true;
                print_stick(sticks[i].first);
                cout<<" # ";
                print_stick(sticks[i2].first);
                cout<<" # ";
                print_stick(sticks[i3].first);
                cout<<endl;
            }
        }
    }
return 0;
}