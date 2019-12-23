#include<iostream>
#include<unordered_map>
#define endl '\n'
using namespace std;
unordered_map<long long, bool> check;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,counter=0;
    int k;
    cin>>n>>k;
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