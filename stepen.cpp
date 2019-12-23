#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXN = 1e6+3;
vector<pair<int,int>> res;
bool used[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin>>x;
    int counter;
    for(int i=2;i*i<=x;++i){
        if(x%i==0 and !used[i]){
            int num=x;
            counter=0;
            while(num%i==0){
                num/=i;
                ++counter;
            }
            if(num==1){
                res.push_back({i,counter});
                used[i]=true;
                int a=i;
                while(counter%2==0 and counter/2>1){
                    counter/=2;
                    a*=a;
                    used[a]=true;
                    res.push_back({a,counter});
                }
            }
        }
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<endl;
    for(int i=res.size()-1;i>=0;--i){
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
return 0;
}