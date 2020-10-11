#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
int cars[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tests;
    cin>>tests;
    
    while(tests--){
        int n;
        cin>>n;
        
        for(int i=0;i<n;++i){
            cin>>cars[i];
            ++cars[i];
        }
        
        int res=0;
        for(int i=0;i<n-1;++i){
            int counter=0;
            bool is_null=false;

            while(i>=0 and cars[i]!=-1){
                ++counter;
                if(cars[i]==1){
                    is_null=true;
                }

                int curr=cars[i];
                cars[i]=-1;
                i=curr-1;
            }
            
            if(counter<2){
                continue;
            }
            
            if(is_null){
                res+=counter-1;
            }else{
                res+=counter+1;
            }
        }
        
        res*=10;
        cout<<res<<endl;
    }
return 0;
}