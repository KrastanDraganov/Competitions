#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN=4e6+3;
int counter[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin>>s;
    
    long long res=0,sum=0;
    int ind=2*(int)s.size();
    for(int i=0;i<s.size();i++){
        if(s[i]=='a' or s[i]=='o' or s[i]=='i' or s[i]=='u' or s[i]=='e'){
            counter[ind++]++;
            sum-=counter[ind];
        }else{
            counter[ind]++;
            sum+=counter[ind];
            ind--;
        }
        res+=sum;
    }
    cout<<res<<endl;
return 0;
}
