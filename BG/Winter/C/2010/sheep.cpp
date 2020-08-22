#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
int weight[MAXN];
bool used[MAXN];

bool check(int capacity, int n, int k){
    for(int i=0;i<n;++i){
        used[i]=false;
    }
    
    int counter=0;
    for(int i=0;i<k;++i){
        int curr=capacity;
        for(int i2=n-1;i2>=0 and curr>=weight[0];--i2){
            if(!used[i2] and weight[i2]<=curr){
                curr-=weight[i2];
                used[i2]=true;
                ++counter;
            }
        }
    }
    
    return counter==n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    int sum=0;
    for(int i=0;i<n;++i){
        cin>>weight[i];
        sum+=weight[i];
    }
    sort(weight,weight+n);
    
    int l=weight[n-1],r=sum;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,n,k)){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<r+1<<endl;
return 0;
}