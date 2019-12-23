#include<bits/stdc++.h>
using namespace std;
unsigned long long ch[1000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    unsigned long long n,num;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int>dig;
        cin>>num;
        while(num!=0){
            dig.push_back(num%10);
            num/=10;
        }
        sort(dig.begin(),dig.end());
        num=0;
        for(int i=dig.size()-1;i>=0;i--){
            num=num*10+dig[i];
        }
        ch[i]=num;
    }
    sort(ch,ch+n);
    unsigned long long br=0,rez=0;
    for(int i=0;i<n;i++){
        if(i==0){
            br=1;
        }else if(ch[i]==ch[i-1]){
            br++;
        }else if(ch[i]!=ch[i-1]){
            if(br!=1) rez+=br;
            br=1;
        }
    }
    if(br!=1) rez+=br;
    cout<<rez<<endl;
return 0;
}