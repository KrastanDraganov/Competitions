//Only 80/100 points

#include<iostream>
#include<algorithm>
#include<vector>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;

    int counter=0;
    vector<int> power;
    for(int i=2;i<=n;++i){
        if(n%i==0){
            int curr=0;
            while(n%i==0){
                n/=i;
                ++curr;
                ++counter;
            }
            for(int i2=2;i2<=curr;++i2){
                power.push_back(i2);
            }
        }
    }
    
    long long ans=1;
    for(int i=2;i<=counter;++i){
        int num=i;
        for(int i2=0;i2<power.size();++i2){
            int gd=__gcd(num,power[i2]);
            num/=gd;
            power[i2]/=gd;
        }
        ans*=(long long)num;
    }
    cout<<ans<<endl;
return 0;
}