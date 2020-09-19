#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    long long sum=0,max_book=0;
    for(int i=0;i<n;++i){
        long long curr;
        cin>>curr;

        sum+=curr;
        max_book=max(max_book,curr);
    }

    cout<<max(sum,2*max_book)<<endl;
return 0;
}