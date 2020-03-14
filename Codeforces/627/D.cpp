#include<iostream>
#include<algorithm>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int teacher[MAXN],student[MAXN];
vector<int> bigger,smaller;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>teacher[i];
    }
    for(int i=0;i<n;++i){
        cin>>student[i];
        if(teacher[i]>student[i]){
            bigger.push_back(teacher[i]-student[i]);
        }else{
            smaller.push_back(student[i]-teacher[i]);
        }
    }
    sort(bigger.begin(),bigger.end());
    sort(smaller.begin(),smaller.end());
    long long res,m=bigger.size();
    int i2=0;
    res=m*(m-1)/2;
    for(int i=0;i<m;++i){
        while(i2<smaller.size() and bigger[i]>smaller[i2]){
            ++i2;
        }
        res+=i2;
    }
    cout<<res<<endl;
return 0;
}