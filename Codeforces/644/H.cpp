#include<iostream>
#include<set>
 
#define endl '\n'
 
using namespace std;
 
set<long long> removed;
 
void add(long long& num){
    ++num;
    while(removed.count(num)>0){
        ++num;
    }
}
 
void decrease(long long& num){
    --num;
    while(removed.count(num)>0){
        --num;
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tests;
    cin>>tests;
    while(tests--){
        int n,m;
        cin>>n>>m;
        removed.clear();
 
        long long median=(1ll<<(m-1))-1,all=(1ll<<m);
        for(int i=0;i<n;++i){
            string s;
            cin>>s;
            long long curr=0;
            for(int i2=0;i2<m;++i2){
                curr=2*curr+(s[i2]-'0');
            }
            removed.insert(curr);
            if(curr==median){
                if(all%2==0){
                    add(median);
                }else{
                    decrease(median);
                }
            }else if(curr<median){
                if(all%2==0){
                    add(median);
                }
            }else{
                if(all%2==1){
                    decrease(median);
                }
            }
            --all;
        }

        for(int i=m-1;i>=0;--i){
            cout<<((median>>i) & 1ll);
        }
        cout<<endl;
    }
return 0;
}