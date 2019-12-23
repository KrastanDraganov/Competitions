#include<iostream>
#include<stack>
#include<utility>
#define endl '\n'
using namespace std;
const int MAXN=1e6+3;
int height[MAXN],right_pos[MAXN],right_val[MAXN],left_pos[MAXN],left_val[MAXN];
pair<int,int> query[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>height[i];
    }
    int k;
    cin>>k;
    for(int i=0;i<k;++i){
        int pos,change;
        cin>>pos>>change;
        height[pos]+=change;
        query[i]={pos,change};
    }
    stack<int> prev;
    long long water_size=0;
    int last=0;
    for(int i=0;i<n;++i){
        if(prev.empty()){
            last=height[i];
            prev.push(i);
        }else if(height[i]>=last){
            while(prev.size()>1){
                prev.pop();
            }
            water_size+=(long long)last*(i-prev.top());
            prev.pop();
            prev.push(i);
            last=height[i];
        }else{
            while(height[i]>=height[prev.top()]){
                prev.pop();
            }
            prev.push(i);
        }
    }
    while(prev.size()>1){
        int curr=prev.top();
        prev.pop();
        water_size+=(long long)height[curr]*(curr-prev.top());
    }
    prev.pop();
    left_pos[0]=left_val[0]=right_pos[n-1]=right_val[n-1]=-1;
    last=0;
    for(int i=1;i<n;++i){
        left_pos[i]=last;
        left_val[i]=height[last];
        if(height[i]>height[last]){
            last=i;
        }
    }
    last=n-1;
    for(int i=n-2;i>=0;--i){
        right_pos[i]=last;
        right_val[i]=height[last];
        if(height[i]>height[last]){
            last=i;
        }
    }
    int useless=0;
    for(int i=0;i<k;++i){
        int pos=query[i].first,change=query[i].second;
        if(pos==0){
            if(right_val[pos]<=height[pos]-change){
                ++useless;
                height[pos]-=change;
            }
        }else if(pos==n-1){
            if(left_val[pos]<=height[pos]-change){
                ++useless;
                height[pos]-=change;
            }
        }else if(left_val[pos]==right_val[pos]
                 or (left_val[pos]<=height[pos]-change and right_val[pos]<=height[pos]-change)
                 or (left_val[pos]>=height[pos] and right_val[pos]>=height[pos])){
            ++useless;
            height[pos]-=change;
        }
    }
    cout<<k-useless<<" "<<water_size<<endl;
return 0;
}
