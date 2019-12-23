#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool br[10001][28];
int obshto[28];

int main(){

ios_base::sync_with_stdio(false);
cin.tie();

long long n,m,k;
string a;
cin>>n>>m>>k;

for(int i=0;i<n;i++){
    cin>>a;
    for(int j=0;j<a.size();j++){
        br[i][a[j]-'a']=true;
    }
}

for(int i=0;i<28;i++){
    for(int j=0;j<n;j++){
        if(br[j][i]>0){
            obshto[i]++;
        }
    }
}

queue<int>ans;
int nai=0;
for(int i=0;i<28;i++){
    if(obshto[i]==nai){
        ans.push(i);
    }
    if(obshto[i]>nai){
        while(!ans.empty())ans.pop();
        nai=obshto[i];
        ans.push(i);
    }
}

if(k==1){
char otg=ans.front()+'a';
cout<<nai<<endl<<otg<<endl<<ans.size()<<endl;
}else{
cout<<"0"<<endl;
}


return 0;
}
