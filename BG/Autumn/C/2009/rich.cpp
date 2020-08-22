//Only 90/100 points

#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1001;
int counter[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,all=0;
    while(cin>>n){
        if(n<MAXN){
            ++counter[n];
            ++all;
        }
    }
    if(n<MAXN){
        --counter[n];
        --all;
    }
    
    int ind=-1;
    for(int i=0;i<MAXN;++i){
        if(counter[i]>0){
            ind=i;
            break;
        }
    }
    
    int res=0;
    while(ind<MAXN and n>0){
        for(int i=ind+1;i<MAXN;++i){
            n-=counter[ind];
            if(n==0){
                res=i;
            }else if(n<0){
                res=i-1;
            }
            if(counter[i]>0 or n<=0){
                counter[i]+=counter[ind];
                ind=i;
                break;
            }else if(i==1000){
                ind=MAXN;
            }
        }
    }
    if(n>0){
        res=(n/all)+1000;
    }
    cout<<res<<endl;
return 0;
}