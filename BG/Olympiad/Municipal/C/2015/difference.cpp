#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=53;
int maxn[MAXN],minn[MAXN],res[MAXN];

bool cmp(int dig1, int dig2){
    return dig1>dig2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin>>s;
    
    int n=(int)s.size();
    for(int i=0;i<n;++i){
        maxn[i]=s[i]-'0';
        minn[i]=maxn[i];
    }
    sort(maxn,maxn+n,cmp);
    sort(minn,minn+n);
    
    if(minn[0]==0){
        int ind=1;
        while(minn[ind]==0){
            ++ind;
        }
        swap(minn[0],minn[ind]);
    }
    
    if(maxn[0]==0){
        int ind=1;
        while(maxn[ind]==0){
            ++ind;
        }
        swap(maxn[0],maxn[ind]);
    }
    
    for(int i=n-1;i>=0;--i){
        if(maxn[i]<minn[i]){
            int ind=i-1;
            while(maxn[ind]==0){
                maxn[ind]=9;
                --ind;
            }
            --maxn[ind];
            maxn[i]+=10;
        }
        res[i]=maxn[i]-minn[i];
    }
    
    for(int i=0;i<n;++i){
        cout<<res[i];
    }
    cout<<endl;
return 0;
}