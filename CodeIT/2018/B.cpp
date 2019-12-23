#include<iostream>
#include<algorithm>
#define endl '\n'
#define MAXN 300005
using namespace std;
int nums[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,result=0;
    bool j=false,j2=false;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        for(int i2=i-10;i2<i;i2++){
            if(i2<0) continue;
            int mm = min(nums[i],nums[i2]),aa = abs(i-i2);
            int curr = mm/aa;
            //cout<<result<<" "<<aa<<" "<<mm<<" "<<curr<<endl;
            if(result==0 and !j){
                j=true;
                result=curr;
            }else if(curr<result){
                result=curr;
            }
            if(result==0){
                cout<<0<<endl;
                return 0;
            }
        }
    }
    cout<<result<<endl;
return 0;
}