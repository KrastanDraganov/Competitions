#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
int unitA[MAXN],unitB[MAXN],real_ind[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>unitA[i];
        real_ind[i]=i;
    }
    for(int i=0;i<n;++i){
        cin>>unitB[i];
    }

    int timer=unitA[0]+unitB[n-1];
    for(int i=0;i<n-1;++i){
        timer+=max(unitB[i],unitA[i+1]);
    }
    for(int i=0;i<k;++i){
        cout<<timer<<endl;
        if(i<k-1){
            int l,r;
            cin>>l>>r;
            --l;
            --r;
            if(l==0){
                timer-=unitA[l];
                timer+=unitA[r];
            }else{
                timer-=max(unitA[l],unitB[l-1]);
                timer+=max(unitA[r],unitB[l-1]);
            }    
            if(r==n-1){
                timer-=unitB[r];
                timer+=unitB[l];
            }else{
                timer-=max(unitB[r],unitA[r+1]);
                timer+=max(unitB[l],unitA[r+1]);
            }
            if(l+1<r){
                timer-=max(unitB[l],unitA[l+1]);
                timer+=max(unitB[r],unitA[l+1]);
                timer-=max(unitA[r],unitB[r-1]);
                timer+=max(unitA[l],unitB[r-1]);
            }
            swap(unitA[l],unitA[r]);
            swap(unitB[l],unitB[r]);
        }
    }
return 0;
}