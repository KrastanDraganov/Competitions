#include<iostream>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
pair<long long, long long> fence[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        int from,to;
        cin>>from>>to;
        fence[i]={from,to};
    }

    long long dist=0,last=fence[n-1].second;
    int ind=n-1,counter=0;
    while(last>=fence[0].first){
        long long dye=k;
        dist+=last;
        while(ind>=0 and dye-(last-fence[ind].first+1)>=0){
            dye-=last-fence[ind].first+1;
            --ind;
            last=(ind<0 ? 0 : fence[ind].second);
        }
        if(dye>0){
            last=(ind<0 ? 0 : last-dye);
        }
        ++counter;
    }
    dist*=2;
    cout<<dist<<endl;
return 0;
}