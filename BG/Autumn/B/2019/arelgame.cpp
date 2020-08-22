#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a,b;
    cin>>a>>b;
    
    long long c=__gcd(a,b);
    if(a>b){
        swap(a,b);
    }
    
    cout<<min(a/(b/c),(b/c-1)/(a/c))<<endl;
return 0;
}