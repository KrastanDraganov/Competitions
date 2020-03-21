#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int pleasure[MAXN],type[MAXN],dist[MAXN],tree[5][4*MAXN];

int find_ans(int ind, int tbegin, int tend, int left, int right, int ctype){
    if(tbegin>tend or right<tbegin or left>tend){
        return -1e8;
    }
    int mid=(tbegin+tend)/2;
    if(left<=tbegin and tend<=right){
        return tree[ctype][ind];
    }
    return max(find_ans(2*ind,tbegin,mid,left,right,ctype),find_ans(2*ind+1,mid+1,tend,left,right,ctype));
}

void update_tree(int ind, int tbegin, int tend, int pos, int val, int ctype){
    int mid=(tbegin+tend)/2;
    if(tbegin==tend){
        tree[ctype][ind]=val;
        return;
    }
    if(pos<=mid){
        update_tree(2*ind,tbegin,mid,pos,val,ctype);
    }else{
        update_tree(2*ind+1,mid+1,tend,pos,val,ctype);
    }
    tree[ctype][ind]=max(tree[ctype][2*ind],tree[ctype][2*ind+1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>pleasure[i]>>type[i]>>dist[i];
    }
    for(int i=0;i<5;++i){
        for(int i2=0;i2<MAXN;++i2){
            tree[i][i2]=-1e8;
        }
    }
    int res=pleasure[n-1];
    for(int i=0;i<5;++i){
        update_tree(1,0,n-1,n-1,res+i+1,i);
    }
    for(int i=n-2;i>=0;--i){
        int farthest=i+dist[i];
        if(i>=n){
            farthest=n-1;
        }
        res=pleasure[i]+find_ans(1,0,n-1,i,farthest,type[i]-1)-(n-i)*type[i];
        for(int i2=0;i2<5;++i2){
            update_tree(1,0,n-1,i,res+(i2+1)*(n-i),i2);
        }
    }
    cout<<res<<endl;
return 0;
}