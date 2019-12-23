#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MAXN=2*1e5+2;
pair<int,pair<int,int>> tree[4*MAXN];
int nums[MAXN],l,r,ans1,ans2,ans3;
void find_answers(int ind,int tbegin,int tend){
    int mid=(tbegin+tend)/2;
    if(l<=tbegin and tend<=r){
        if(tree[ind].first==ans1){
            ans2+=tree[ind].second.first;
        }else if(tree[ind].first<ans1){
            ans2=tree[ind].second.first;
        }
        ans1=min(ans1,tree[ind].first);
        ans3=__gcd(ans3,tree[ind].second.second);
        return;
    }
    if(l<=mid){
        find_answers(2*ind,tbegin,mid);
    }
    if(r>mid){
        find_answers(2*ind+1,mid+1,tend);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q,pow=1;
    cin>>n;
    while(pow<n){
        pow*=2;
    }
    for(int i=0;i<n;i++){
        cin>>nums[i];
        tree[pow+i]={nums[i],{1,nums[i]}};
    }
    for(int i=0;i<pow%n;i++){
        tree[pow+n+i]={INT_MAX,{1,nums[n-1]}};
    }
    for(int i=pow-1;i>=1;i--){
        tree[i].first=min(tree[2*i].first,tree[2*i+1].first);
        if(tree[2*i].first<tree[2*i+1].first){
            tree[i].second.first=tree[2*i].second.first;
        }else if(tree[2*i].first>tree[2*i+1].first){
            tree[i].second.first=tree[2*i+1].second.first;
        }else if(tree[2*i].first==tree[2*i+1].first){
            tree[i].second.first=tree[2*i+1].second.first+tree[2*i].second.first;
        }
        tree[i].second.second=__gcd(tree[2*i+1].second.second,tree[2*i].second.second);
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>l>>r;
        l--;
        r--;
        ans1=INT_MAX;
        ans2=0;
        ans3=0;
        find_answers(1,0,pow-1);
        cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    }
return 0;
}