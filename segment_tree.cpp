#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MAXN=1e5;
int tree[4*MAXN],nums[MAXN],ans;
void find_ans(int ind,int tbegin,int tend,int left,int rigth){
    int mid=(tbegin+tend)/2;
    if(left<=tbegin and tend<=rigth){
        ans=max(ans,tree[ind]);
        return;
    }
    if(left<=mid){
        find_ans(2*ind,tbegin,mid,left,rigth);
    }
    if(rigth>mid){
        find_ans(2*ind+1,mid+1,tend,left,rigth);
    }
}
void update_tree(int ind,int tbegin,int tend,int pos,int val){
    int mid=(tbegin+tend)/2;
    if(tbegin==tend){
        tree[ind]=val;
        return;
    }
    if(pos<=mid){
        update_tree(2*ind,tbegin,mid,pos,val);
    }else{
        update_tree(2*ind+1,mid+1,tend,pos,val);
    }
    tree[ind]=max(tree[2*ind],tree[2*ind+1]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int pow=1;
    while(pow<n){
        pow*=2;
    }
    for(int i=0;i<n;i++){
        tree[pow+i]=nums[i];
    }
    for(int i=pow-1;i>=1;i--){
        tree[i]=max(tree[2*i],tree[2*i+1]);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int type,l,r;
        cin>>type>>l>>r;
        if(type==1){
            ans=0;
            find_ans(1,0,pow-1,l,r);
            cout<<ans<<endl;
        }else{
            update_tree(1,0,pow-1,l,r);
        }
    }
return 0;
}