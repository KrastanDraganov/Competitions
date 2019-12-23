#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;
int counter[300005];
vector<int> possible,possible2;
pair<int,int> nums[300005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        nums[i]={x,y};
        ++counter[y];
        ++counter[x];
    }
    int cmax=0;
    for(int i=1;i<=300000;++i){
        if(counter[i]>cmax){
            cmax=counter[i];
            possible.clear();
            possible.push_back(i);
        }else if(counter[i]==cmax){
            possible.push_back(i);
        }
    }
    if(possible.size()==1){
        int cmax2=0;
        for(int i=1;i<=300000;++i){
            if(counter[i]>cmax2 and counter[i]<cmax){
                cmax2=counter[i];
                possible2.clear();
                possible2.push_back(i);
            }else if(counter[i]==cmax){
                possible2.push_back(i);
            }
        }
        for(int i=0;i<possible2.size();++i){
            possible.push_back(possible2[i]);
        }
    }
    for(int i=0;i<possible.size();++i){
        for(int i2=0;i2<possible.size();++i2){
            if(i!=i2){
                bool j=true;
                for(int i3=0;i3<m;++i3){
                    if(possible[i]!=nums[i3].first and possible[i2]!=nums[i3].first and possible[i]!=nums[i3].second and possible[i2]!=nums[i3].second){
                        j=false;
                        break;
                    }
                }
                if(j){
                    cout<<"YES\n";
                    return 0;
                }
            }
        }
    }
    cout<<"NO\n";
return 0;
}