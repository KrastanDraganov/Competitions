#include<iostream>
#include<string>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1003;
int divisors[MAXN];
vector<int> res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        for(int i=2;i*i<=curr;++i){
            int counter=0;
            while(curr%i==0){
                curr/=i;
                ++counter;
            }
            divisors[i]=max(divisors[i],counter);
        }
        divisors[curr]=max(divisors[curr],1);
    }
    
    res.push_back(1);
    for(int div=2;div<MAXN;++div){
        for(int counter=0;counter<divisors[div];++counter){
            int prev=0;
            for(int i=0;i<res.size();++i){
                res[i]=res[i]*div+prev;
                prev=res[i]/10;
                res[i]%=10;
            }
            while(prev>0){
                res.push_back(prev%10);
                prev/=10;
            }
        }
    }
    for(int i=res.size()-1;i>=0;--i){
        cout<<res[i];
    }
    cout<<endl;
return 0;
}