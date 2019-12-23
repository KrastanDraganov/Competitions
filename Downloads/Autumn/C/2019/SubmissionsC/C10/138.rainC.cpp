#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;
long long N, a[1000003], ans, num, high, otg[1000003], c, uv, ans1, br, K;
pair<long long , long long> b[2000003];
int main() {
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>a[i];
        b[i]={a[i], i};
    }
    sort(b, b+N, greater<pair<long long, long long> >());
    for(int i=1; i<N; i++){
        num=b[i].second;
        high=b[i].first;
        for(int j=min(b[i-1].second, num); j<max(num,b[i-1].second); j++){
            if(otg[j]==0){
                otg[j]=high;
                ans+=high;
            }
        }
    }
    cin>>K;
    for(int i=0; i<K; i++){
        ans1=0;
        cin>>c>>uv;
        b[N+i]={uv+a[c], c};
        sort(b, b+N+i+1, greater<pair<long long, long long> >());
        for(int i=0; i<N; i++)otg[i]=0;
        for(int q=1; q<=N+i; q++){
            num=b[q].second;
            high=b[q].first;
            for(int j=min(b[q-1].second, num); j<max(num,b[q-1].second); j++){
                if(otg[j]==0){
                    otg[j]=high;
                    ans1+=high;
                }
            }
        }
        if(ans1>ans)br++;
    }
    cout<<br<<" "<<ans1;
    return 0;
}
