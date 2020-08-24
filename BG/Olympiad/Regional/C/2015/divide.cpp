#include<iostream>

#define endl '\n'

using namespace std;

long long needed[32],packs[32];

void calc(int num){
    for(int i=0;num;++i){
        if(num & 1){ 
            ++needed[i];
        }
        num/=2;
    }
}

void create_packs(int curr, int& res){
    if(packs[curr+1]>0){
        packs[curr+1]--;
        packs[curr]+=2;
        res++;
    }else{
        create_packs(curr+1,res);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,a,b;
    cin>>n>>a>>b;
    
    calc(a);
    calc(b);

    int res=0;
    packs[n]=1;
    while(true){
        bool is_change=false;
        for(int i=31;i>=0;i--){
            if(needed[i]>packs[i]){
                is_change=true;
                create_packs(i,res);
            }
        }
        if(!is_change){
            break;
        }
    }
    cout<<res<<endl;
return 0;
}
