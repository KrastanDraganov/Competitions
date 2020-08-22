#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

bool used[13];

long long to_num(string x){
    if((int)x.size()>10){ 
        return 1e10;
    }
    long long res=0;
    for(char curr : x){
        res=10*res+(curr-'0');
    }
    return res;
}

int sol(long long x, long long numa, long long numb){
    if(x>numb) return 0;
    int res=(x>=numa and x<=numb);
    for(int i=(!x);i<10;++i){
        if(!used[i]){
            used[i]=true;
            res+=sol(10*x+i,numa,numb);
            used[i]=false;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a,b;
    cin>>a>>b;
    
    long long numa=to_num(a);
    long long numb=to_num(b);
    
    cout<<sol(0,numa,numb)<<endl;
return 0;
}