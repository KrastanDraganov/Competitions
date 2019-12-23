#include<iostream>
#include<iomanip>
#define MAXN 25
using namespace std;
void fill_matrix(int nums[][MAXN], int n){
    int len=n,pos=0,num=1;
    while(num<=n*n){
        for(int i=pos;i<len;++i){
            nums[i][pos]=num++;
        }
        for(int i=pos+1;i<len;++i){
            nums[len-1][i]=num++;
        }
        for(int i=len-2;i>=pos;--i){
            nums[i][len-1]=num++;
        }
        for(int i=len-2;i>pos;--i){
            nums[pos][i]=num++;
        }
        ++pos;
        --len;
    }
}
void print_matrix(int nums[][MAXN], int n){
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            cout<<setw(3)<<nums[i][i2];
        }
        cout<<endl;
    }
}
int main(){
    int n,nums[MAXN][MAXN];
    cin>>n;
    fill_matrix(nums,n);
    print_matrix(nums,n);
return 0;
}