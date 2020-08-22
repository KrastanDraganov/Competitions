#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    int sum=0,start_ind=0,res_start=-1,res_end=-1,max_sum=-1e9;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        sum+=curr;
        if(sum>=max_sum){
            max_sum=sum;
            res_end=i;
            res_start=start_ind;
        }
        if(sum<0){
            sum=0;
            start_ind=i+1;
        }
    }
    cout<<max_sum<<" "<<res_start+1<<" "<<res_end+1<<endl;
return 0;
}