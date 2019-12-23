#include<bits/stdc++.h>
#define N 100005
using namespace std;
bool j2[N];
int main(){
    string s;
    cin>>s;
    bool j=true;
    unsigned long long sec=0,br=0;
    while(j){
        j=false;
        memset(j2,0,N);
        for(int i=1;i<s.size();i++){
            if(s[i]=='L' and s[i-1]=='R' and j2[i-1]==false){
                j=true;
                br++;
                s[i]='R';
                s[i-1]='L';
                j2[i]=true;
            }
        }
        sec++;
    }
    cout<<sec-1<<" "<<br<<endl;
return 0;
}