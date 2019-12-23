#include<bits/stdc++.h>
using namespace std;
const int BEGIN=0,END=1;
pair<int,pair<int,int>>ch[1005];
int main(){
    int n,a,b,c,d,i2=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        ch[i2++]=make_pair(a,make_pair(b,BEGIN));
        ch[i2++]=make_pair(c,make_pair(d,END));
    }
    sort(ch,ch+i2);
    int br=0;
    for(int i=0;i<i2;i++){
        if(ch[i].second.second==BEGIN) br++;
        else br--;
        
    }