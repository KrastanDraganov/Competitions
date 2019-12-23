#include<bits/stdc++.h>
using namespace std;
int a[27][10005];
bool b[27][1500][1500];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    string s;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<s.size();j++){
           if(a[s[j]-'a'][i]==0){
                a[s[j]-'a'][i]=j+1;///                                                 !!!
           }
        }
    }
    if(k==1){
        int x=0,y=0,z=0,h;
        for(int i=0;i<26;i++){
            h=0;
            for(int j=0;j<n;j++){
                if(a[i][j])h++;
            }
            if(h>y){
                x=i;
                y=h;
                z=1;
            }else if(h==y){
                z++;
            }
        }
        cout<<y<<endl;
        cout<<char(x+'a')<<endl;
        cout<<z<<endl;
    }else{
        cout<<0<<endl;
    }
    return 0;
}
/*
6
2 4 2 4 2 1
2
2 1
4 1
*/
