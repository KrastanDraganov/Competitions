#include<iostream>
#include<utility>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=22;
pair<int,int> hours[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int from,to;
        cin>>from>>to;
        hours[i]={to,from};
    }
    
    sort(hours,hours+n);
    int res=0,prev_elly=-1,prev_chris=-1;
    for(int i=0;i<n;++i){
        pair<int,int> curr=hours[i];
        if(curr.second>=prev_elly){
            ++res;
            prev_elly=curr.first;
        }else if(curr.second>=prev_chris){
            ++res;
            prev_chris=curr.first;
        }
        if(prev_chris>prev_elly){
            swap(prev_chris,prev_elly);
        }
    }
    cout<<res<<endl;
return 0;
}