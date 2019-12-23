#include<iostream>
#include<algorithm>
#define endl '\n'
#define MAXN 105
using namespace std;
int table[MAXN][MAXN],all_nums[MAXN*MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,p;
    cin>>n>>p;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            cin>>table[i][i2];
            all_nums[n*i+i2]=table[i][i2];
        }
    }
    sort(all_nums,all_nums+n*n);
    int counter=0,border=((double)p/100)*n*n,res=n*n;
    for(int i=0;i<n;++i){
        ++counter;
        if(table[0][i]>=all_nums[border-1]){
            res=counter;
        }
        for(int i2=i-1,i3=1;i2>=0 and i3<n;--i2,++i3){
            ++counter;
            if(table[i3][i2]>=all_nums[border-1]){
                res=counter;
            }
        }
    }
    for(int i=1;i<n;++i){
        ++counter;
        if(table[i][n-1]>=all_nums[border-1]){
            res=counter;
        }
        for(int i2=i+1,i3=n-2;i2<n and i3>=0;++i2,--i3){
            ++counter;
            if(table[i2][i3]>=all_nums[border-1]){
                res=counter;
            }
        }
    }
    cout<<res<<endl;
return 0;
}