#include<iostream>
#include<set>

#define endl '\n'

using namespace std;

const int MAXN=8e3+3;
int nums[MAXN];
bool used[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>nums[i];
            used[i+1]=false;
        }

        for(int i=0;i<n;++i){
            int curr=nums[i];
            for(int i2=i+1;i2<n;++i2){
                curr+=nums[i2];
                if(curr>n){
                    break;
                }
                used[curr]=true;
            }
        }
        int res=0;
        for(int i=0;i<n;++i){
            res+=used[nums[i]];
        }
        cout<<res<<endl;
    }
return 0;
}