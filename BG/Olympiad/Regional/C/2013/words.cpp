#include<iostream>
#include<string>

using namespace std;

const int MAXN=2e4+3;
int prefix[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin>>s;
    
    int counter=1;
    for(int i=0;i<s.size();i++){
        prefix[i]=counter;
        if(i>0 and s[i]<s[i-1]){
            counter++;
            prefix[i]++;
        }
    }
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        --a;
        --b;
        cout<<prefix[b]-prefix[a]+1<<"\n";
    }
return 0;
}