#include<iostream>
#include<vector>
#include<utility>
#include<unordered_map>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAX_DIFF=200;
const int MAXM=2*MAX_DIFF+3;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<pair<int, int>> coords(n);
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        coords[i]={x, y};
    }

    vector<vector<int>> counter(MAXM, vector<int>(MAXM));
    int res=0;

    for(int i=0;i<n;++i){
        for(int i2=0;i2<MAXM;++i2){
            for(int i3=0;i3<MAXM;++i3){
                counter[i2][i3]=0;
            }
        }

        int curr_max=0;
        for(int j=0;j<n;++j){
            if(i==j){
                continue;
            }

            int diff_x=coords[i].first-coords[j].first;
            int diff_y=coords[i].second-coords[j].second;
            
            if(diff_x==0){
                diff_y=1;
            }else if(diff_y==0){
                diff_x=1;
            }else{
                int gcd=__gcd(diff_x, diff_y);
                diff_x/=gcd;
                diff_y/=gcd;
            }

            diff_x+=MAX_DIFF;
            diff_y+=MAX_DIFF;

            ++counter[diff_x][diff_y];
            curr_max=max(curr_max, counter[diff_x][diff_y]);
        }

        res=max(res, curr_max+1);
    }

    cout<<res<<endl;
return 0;
}