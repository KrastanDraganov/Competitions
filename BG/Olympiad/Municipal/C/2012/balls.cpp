#include<iostream>
#include<unordered_map>

#define endl '\n'

using namespace std;

unordered_map<long long, bool> check;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    int k;
    cin>>n>>k;

    long long counter=0;
    for(int i=0;i<k;++i){
        long long num;
        cin>>num;
        if(check[num]==false){
            check[num]=true;
            ++counter;
        }
    }
    
    cout<<n-counter<<endl;
return 0;
}