#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    int ans=0;
    for(int i=0;i<n;++i){
        unsigned long long num;
        cin>>num;
        
        bool check=false;
        while(num>0){
            int dig=num%10;
            if(dig==3){
                check=true;
            }else if(dig==1 and check){
                ++ans;
                break;
            }
            num/=10;
        }
    }
    
    if(ans>0){
        cout<<ans<<endl;
    }else{
        cout<<"No\n";
    }
return 0;
}