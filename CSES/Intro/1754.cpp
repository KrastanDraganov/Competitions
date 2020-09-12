#include<iostream>

#define endl '\n'

using namespace std;

bool check(int a, int b){
    if(a>b){
        swap(a,b);
    }

    int diff=b-a;
    if(diff>a){
        return false;
    }
    
    a-=diff;
    b-=(2*diff);

    return (a==0 or (a%3==0));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;

    while(tests--){
        int a,b;
        cin>>a>>b;

        cout<<(check(a,b) ? "YES" : "NO")<<endl;
    }
return 0;
}