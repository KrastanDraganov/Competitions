#include<iostream>
#include<fstream>
#include<stdlib.h> 
#include<time.h> 
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXN=1e4+3;
int nums[MAXN];
ofstream fout("/media/fif2205/Mined/Competitions/triples2.in");
ofstream fout2("/media/fif2205/Mined/Competitions/triples2.out");
int main(){
    srand(time(0)); 
    int n=1e3;
    fout<<n<<endl;
    long long res=0;
    for(int i=0;i<n;++i){
        nums[i]=rand()%10000;
        fout<<nums[i]<<endl;
    }
    sort(nums,nums+n);
    for(int i=0;i<n-2;++i){
        for(int i2=i+1;i2<n-1;++i2){
            for(int i3=i2+1;i3<n;++i3){
                int diff1=nums[i2]-nums[i],diff2=nums[i3]-nums[i2];
                if(diff2>=diff1 and diff2<=2*diff1){
                    ++res;
                }
            }
        }
    }
    fout2<<res<<endl;
return 0;
}