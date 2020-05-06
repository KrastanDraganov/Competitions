#include<iostream>
#include<string>
#include<algorithm>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b;
    cin>>a>>b;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int res=0;
    for(int i=0;i<a.size();++i){
        int min_change=1e9,ind=-1,l=a[i]-'A';
        for(int i2=0;i2<b.size();++i2){
            if(b[i2]!='u'){
                int r=b[i2]-'A';
                if(r<l){
                    r+=26;
                }
                if(r-l<min_change){
                    min_change=r-l;
                    ind=i2;
                }
            }
        }
        res+=min_change;
        b[ind]='u';
    }
    cout<<res<<endl;
return 0;
}