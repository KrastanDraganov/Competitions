#include<iostream>
#include<vector>
#include<unordered_set>

#define endl '\n'

using namespace std;

unordered_set<long long> squares;
vector<long long> res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x;
    cin>>x;
    
    for(long long i=0;i<=(1+x)/2+1;i++){
        squares.insert(i*i);
    }
    for(long long i=0;i<=(1+x)/2+1;i++){
         if(squares.find(i*i-x)!=squares.end()){
            res.push_back(i);
         }
    }
    
    cout<<(int)res.size()<<endl;
    for(int i=0;i<res.size();i++){ 
        cout<<res[i]*res[i]<<" "<<res[i]*res[i]-x<<endl;
    }
return 0;
}
