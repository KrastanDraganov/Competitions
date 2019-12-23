#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXN = 1e5+3;
int stones[MAXN];
bool cmp(int a, int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>stones[i];
    }
    sort(stones,stones+n,cmp);
    int ind=0,change=0;
    long long energy=0;
    while(ind<n){
        if(stones[ind]-change<1){
            break;
        }
        int counter=1;
        while(ind+1<n and stones[ind]==stones[ind+1]){
            ++counter;
            ++ind;
        }
        energy+=(long long)(stones[ind]-change)*counter;
        change+=counter;
        ++ind;
    }
    cout<<energy<<endl;
return 0;
}