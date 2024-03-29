#include<iostream>
#include<string>
#include<vector>

#define endl '\n'

using namespace std;

bool check(int mid, int limit, int n, int m, vector<int>& endings){
    int counter=0,prev=1-m;

    for(int ind : endings){
        if(ind-prev>=n+mid){
            ++counter;
            prev=ind;
        }
    }

    return counter>=limit;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s,word;
    int k;
    cin>>s>>word>>k;
    
    unsigned long long word_code=0,s_code=0;
    int n=(int) word.size(),m=(int) s.size();

    for(int i=0;i<n;++i){
        if(word[i]=='b'){
            word_code |= (1LL<<i);
        }
        if(s[i]=='b'){
            s_code |= (1LL<<i);
        }
    }
    
    vector<int> endings;
    if(s_code==word_code){
        endings.push_back(n-1);
    }
    for(int i=n;i<m;++i){
        s_code>>=1;
        if(s[i]=='b'){
            s_code |= (1LL<<(n-1));
        }
        if(s_code==word_code){
            endings.push_back(i);
        }
    }

    int left=0,right=(int)m-1;
    while(left<=right){
        int mid=(left+right)/2;
        
        if(check(mid,k,n,m,endings)){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }

    cout<<right<<endl;
return 0;
}