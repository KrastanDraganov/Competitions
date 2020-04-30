#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int happy[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    int start_ind=0,res_start=0,res_end=0;
    long long res=-1e9,sum=0;
    for(int i=0;i<n;++i){
        cin>>happy[i];
        sum+=(long long) happy[i];
        if(sum>res){
            res=sum;
            res_start=start_ind+1;
            res_end=i+1;
        }
        if(sum<0ll){
            sum=0ll;
            start_ind=i+1;
        }
    }
    cout<<res<<" "<<res_start<<" "<<res_end<<endl;
return 0;
}