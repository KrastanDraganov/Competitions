#include<bits/stdc++.h>
using namespace std;
int n,a,b;
long long needed[32],packs[32],res=0;
void calc(int num){
    for(int i=0;num>0;i++){
        if(num%2==1) needed[i]++;
        num/=2;
    }
}
void createPacks(int i2){
    if(packs[i2+1]>0){
        packs[i2+1]--;
        packs[i2]+=2;
        res++;
    }else{
        createPacks(i2+1);
    }
}
int main(){
    cin>>n>>a>>b;
    calc(a);
    calc(b);
    bool j=true;
    packs[n]=1;
    while(j){
        j=false;
        for(int i=31;i>=0;i--){
            if(needed[i]>packs[i]){
                j=true;
                createPacks(i);
            }
        }
    }
    cout<<res<<endl;
return 0;
}
