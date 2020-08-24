#include<iostream>
#include<algorithm>
#include<utility>

#define endl '\n'

using namespace std;

pair<int,int> cord[7];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0;i<6;++i){
        int x,y;
        cin>>x>>y;
        if(x>y){
            swap(x,y);
        }
        cord[i]={x,y};
    }
    
    sort(cord,cord+6);
    if(cord[0].first==cord[1].first and cord[0].first==cord[2].first and cord[0].first==cord[3].first and cord[0].second==cord[1].second and cord[0].second==cord[4].first
    and cord[0].second==cord[5].first and cord[2].second==cord[3].second and cord[2].second==cord[4].second and cord[2].second==cord[5].second){
        cout<<(long long)cord[0].first*cord[0].second*cord[2].second<<endl;
    }else{
        cout<<0<<endl;
    }
}