#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXN=103;
int nums[MAXN];
bool can_swap[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;++i){
            cin>>nums[i];
            can_swap[i]=false;
        }
        for(int i2=0;i2<m;++i2){
            int curr;
            cin>>curr;
            can_swap[curr-1]=true;
        }
        for(int i=0;i<n;++i){
            if(can_swap[i]){
                int r=i;
                while(r<n and can_swap[r]){
                    ++r;
                }
                sort(nums+i,nums+r+1);
                i=r;
            }
        }
        bool check=true;
        for(int i=0;i<n-1;++i){
            if(nums[i]>nums[i+1]){
                check=false;
                break;
            }
        }
        cout<<(check ? "YES" : "NO")<<endl;
    }
return 0;
}