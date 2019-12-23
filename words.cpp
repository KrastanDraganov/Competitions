#include<bits/stdc++.h>
using namespace std;
int prefix[20005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int br=1;
    for(int i=0;i<s.size();i++){
        prefix[i]=br;
        //cout<<s[i]<<" "<<br<<endl;
        if(i>0)
        if(s[i]<s[i-1]){
            br++;
            prefix[i]++;
        }
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        cout<<prefix[b-1]-prefix[a-1]+1<<"\n";
    }
return 0;
}