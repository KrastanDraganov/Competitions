#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXN = 1e6+3;
unsigned long long diff[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    unsigned long long m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>diff[i];
    }
    unsigned long long sum=0;
    for(int i=0;i<n;++i){
        unsigned long long achieved;
        cin>>achieved;
        sum+=achieved;
        diff[i]-=achieved;
    }
    sort(diff,diff+n);
    int ind=0;
    unsigned long long left=(unsigned long long)n,days=0,last=0;
    while(ind<n){
        days+=diff[ind]-last;
        //cout<<ind<<" "<<diff[ind]<<" "<<days<<" "<<left<<" "<<sum<<endl;
        sum+=left*(diff[ind]-last);
        if(sum>=m){
            //cout<<days<<" "<<sum<<" "<<m<<endl;
            days=days-((sum-m)/left);
            break;
        }
        while(ind+1<n and diff[ind]==diff[ind+1]){
            ++ind;
            --left;
        }
        last=diff[ind];
        --left;
        ++ind;
    }
    cout<<days<<endl;
return 0;
}