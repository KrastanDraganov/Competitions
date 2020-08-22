#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,d,l,x,a,b;
    cin>>n>>l>>d>>x>>a>>b;
    
    if(d<(l/n)){
        cout<<-1<<endl;
        return 0;
    }
    
    int drops=0,counter=0;
    vector<int> min_drop(l/d+1,l),max_drop(l/d+1,0);
    while(drops<n and counter<(l/d)){
        int ind=x/d;
        if(ind-1>=0 and min_drop[ind]-max_drop[ind-1]>d and x-max_drop[ind-1]<=d){
            ++counter;
        }
        if(ind+1<=(l/d) and min_drop[ind+1]-max_drop[ind]>d and min_drop[ind+1]-x<=d){
            ++counter;
        }
        min_drop[ind]=min(min_drop[ind],x);
        max_drop[ind]=max(max_drop[ind],x);
        x=((long long)x*a+b)%(l+1);
        ++drops;
    }
    cout<<(drops<=n ? drops : -1)<<endl;
return 0;
}