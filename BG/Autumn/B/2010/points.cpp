#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=43;
long long points[MAXN];
vector<long long> sums1,sums2;

void calc_sums(long long sum, int ind, int border, int half, bool change){
    if(change){
        if(half==1){
            sums1.push_back(sum);
        }else{
            sums2.push_back(sum);
        }
    }
    
    if(ind>border){
        return;
    }
    
    calc_sums(sum+points[ind],ind+1,border,half,true);
    calc_sums(sum,ind+1,border,half,false);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long t;
    cin>>n>>t;
    for(int i=0;i<n;++i){
        cin>>points[i];
    }
    sort(points,points+n);
    
    calc_sums(0,0,n/2-1,1,true);
    calc_sums(0,n/2,n-1,2,true);
    sort(sums1.begin(),sums1.end());
    sort(sums2.begin(),sums2.end());
    
    long long res=0,sum=0,r=sums2.size()-1;
    for(auto num : sums1){
        while(r>=0 and sums2[r]+num>=t){
            ++sum;
            --r;
        }
        res+=sum;
    }
    cout<<res<<endl;
return 0;
}