#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=103;
int pass[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>pass[i];
    }
    cin>>m;
    
    int i2=0;
    for(int i=0;i<m;++i){
        int num;
        cin>>num;
        if(num==pass[i2]){
            ++i2;
            continue;
        }
        int sum=num;
        while(sum>0){
            cout<<pass[i2]<<" ";
            sum-=pass[i2];
            ++i2;
        }
    }
    cout<<endl;
return 0;
}