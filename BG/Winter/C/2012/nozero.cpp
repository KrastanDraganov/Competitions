#include<iostream>
#include<stack>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
int nums[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }

    stack<int> nulls;
    long long res=0;
    for(int i=n-1;i>=0;--i){
        if(nums[i]==0){
            nulls.push(i);
        }else if(!nulls.empty()){
            res+=((long long)nulls.top()-i);
            nulls.pop();
        }
    }
    cout<<(nulls.empty() ? res : -1)<<endl;
return 0;
}