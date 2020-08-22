#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

long long fact[17];
bool letter[27];

long long print_result(string x, string y){
    for(int i=0;i<y.size();++i){
        if(letter[y[i]-'a']){
            return 0;
        }
        letter[y[i]-'a']=true;
    }
    
    for(int i=0;i<y.size();++i){
        bool check=false;
        for(int i2=0;i2<x.size();++i2){
            if(y[i]==x[i2]){
                check=true;
                break;
            }
        }
        if(!check){
            return 0;
        }
    }
    
    long long res=0;
    for(int i=0;i<=x.size()-y.size();++i){
        res+=(fact[x.size()-y.size()]/fact[x.size()-y.size()-i])*((long long) i+1);
    }
    return res;
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    fact[0]=1;
    for(int i=1;i<=16;++i){
        fact[i]=fact[i-1]*i;
    }
    
    string s,p;
    cin>>s>>p;
    cout<<print_result(s,p)<<endl;
return 0;
}