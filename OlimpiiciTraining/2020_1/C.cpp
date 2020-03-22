#include<iostream>
#include<string>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=5e5+3;
int tree[MAXN];

void update(int pos, int val, int n){
    while(pos<=n){
        tree[pos]+=val;
        pos+=(pos & (-pos));
    }
}

int sum(int pos){
    int res=0;
    while(pos>0){
        res+=tree[pos];
        pos-=(pos & (-pos));
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<3;++i){
        int k;
        string s;
        cin>>k>>s;
        int curr_pos=0,n=s.size(),orig=s.size();
        --k;
        while(n>1){
            curr_pos=(curr_pos+sum(orig)-sum(curr_pos)+k)%n;
            int new_pos=(curr_pos+sum(curr_pos+1))%n;
            while(new_pos>curr_pos){
                swap(curr_pos,new_pos);
                new_pos=(new_pos+sum(curr_pos+1)-sum(new_pos))%n;
            }
            update(curr_pos+1,1,orig);
            --n;
        }
        bool check=false;
        for(int i=2;i<=orig;++i){
            if(sum(i)-sum(i-1)==0){
                cout<<s[i-1]<<endl;
                check=true;
                break;
            }
        }
        if(!check){
            cout<<s[0]<<endl;
        }
    }
return 0;
}