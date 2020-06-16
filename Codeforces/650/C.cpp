#include<iostream>

#define endl '\n'

using namespace std;

int calc_table(int k, int n, int x, int y){
    int diff=x-y-1,res=0;
    if(x==n and diff>=k+1){
        ++res;
        --diff;
    }
    if(y==-1 and diff>=k+1){
        ++res;
        --diff;
    }
    while(diff>=2*k+1){
        diff-=(k+1);
        ++res;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n,k;
        string tables;
        cin>>n>>k>>tables;

        int last_table=-1,res=0;
        bool is_one=false;
        for(int i=0;i<n;++i){
            if(tables[i]=='1'){
                res+=calc_table(k,n,i,last_table);
                last_table=i;
                is_one=true;
            }
        }
        if(tables[n-1]!='1'){
            res+=calc_table(k,n,n,last_table);
        }
        if(!is_one and n<=k){
            res=1;
        }
        cout<<res<<endl;
    }
return 0;
}