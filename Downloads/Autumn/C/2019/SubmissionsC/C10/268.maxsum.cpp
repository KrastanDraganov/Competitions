#include<iostream>
#include<algorithm>
using namespace std;
long long N, K, d[1003], a[100003], maxsum[100003], maxsum2[100003], ans;
int main() {
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>a[i];
    }
    for(int i=0; i<K; i++){
        cin>>d[i];
    }
    sort(d, d+K);
    maxsum[0]=a[0];
    for(int i=d[0]; i<N-1; i++){
        for(int j=0; j<K; j++){
            if(i-d[j]>=0)maxsum[i]=max(maxsum[i], maxsum[i-d[j]]);
        }
        maxsum[i]+=a[i];
    }
    maxsum2[N-1]=a[N-1];
    for(int i=N-d[0]-1; i>0; i--){
        for(int j=0; j<K; j++){
            if(i+d[j]<N)maxsum2[i]=max(maxsum2[i], maxsum2[i+d[j]]);
        }
        maxsum2[i]+=a[i];
    }
    for(int i=0; i<N-1; i++){
        for(int j=N-1; j>i; j--){
            ans=max(ans, maxsum[i]+maxsum2[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
