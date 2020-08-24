#include<iostream>

#define endl '\n'

using namespace std;

bool used[10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a,b;
    cin>>a>>b;
    
    int res=0;
    for(int i=a;i<=b;++i){
        int num=i;
        bool check=true;
        for(int i=0;i<=9;++i){
            used[i]=false;
        }
        while(num>0){
            if(used[num%10]){
                check=false;
                break;
            }
            used[num%10]=true;
            num/=10;
        }
        res+=check;
    }
    cout<<res<<endl;
return 0;
}