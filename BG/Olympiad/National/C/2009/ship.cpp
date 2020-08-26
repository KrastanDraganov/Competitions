#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e4+3;
int weight[MAXN],pos[MAXN];
bool changed[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    int min_weight=1e9;
    for(int i=0;i<n;++i){
        cin>>weight[i];
        min_weight=min(min_weight,weight[i]);
    }
    for(int i=0;i<n;++i){
        cin>>pos[i];
    }
    
    long long res=0;
    for(int i=0;i<n;++i){
        if(changed[i]){
            continue;
        }
        
        int sum=weight[i],curr_min=weight[i],next_ind=pos[i],counter=0;
        changed[i]=true;
        
        while(next_ind!=i){
            sum+=weight[next_ind];
            curr_min=min(curr_min,weight[next_ind]);
            changed[next_ind]=true;
            ++counter;
            next_ind=pos[next_ind];
        }
        
        sum-=curr_min;
        res+=(long long)sum+min(counter*curr_min,2*(curr_min+min_weight)+counter*min_weight);
    }
    cout<<res<<endl;
return 0;
}