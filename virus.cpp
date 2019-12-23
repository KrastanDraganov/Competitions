#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int>v[105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,p=1;
    cin>>n;
    int counter=0;
    while(p<n){
        p*=2;
        counter++;
    }
    cout<<counter<<endl;
    if(n<=500){
        string s="";
        for(int i=0;i<counter;i++) s+='.';
        int next;
        for(p=1;p<=n;p++){
            for(int i=0;i<counter;i++)
                if(s[i]=='.')
                    v[i+1].push_back(p);
            if(s[counter-1]=='1'){
                for(int i=counter-2;i>=0;i--){
                    if(s[i]=='.'){
                        next=i;
                        break;
                    }
                }
                s[next]='1';
                for(int i=next+1;i<counter;i++) s[i]='.';
            }else{
                s[counter-1]='1';
            }
        }
        for(int i=0;i<counter;i++){
            cout<<v[i].size()<<" ";
            for(int i2=0;i2<v[i].size();i2++){
                cout<<v[i][i2]<<" ";
            }
            cout<<endl;
        }
    }
return 0;
}