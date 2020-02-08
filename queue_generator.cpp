#include<iostream>
#include<fstream>
#include<stdlib.h> 
#include<time.h> 
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXN=1e4+3;
int nums[MAXN];
ofstream fout("/media/fif2205/Mined/Competitions/queue2.in");
ofstream fout2("/media/fif2205/Mined/Competitions/queue2.out");
int main(){
    srand(time(0)); 
    int n=10;
    fout<<n<<endl;
    long long res=0;
    for(int i=0;i<n;++i){
        nums[i]=rand()%100;
        fout<<nums[i]<<endl;
    }
    for(int i=1;i<n;++i){
        int max_height=0;
        for(int i2=i-1;i2>=0;--i2){
            if(nums[i2]>=max_height){
                ++res;
            }
            max_height=max(max_height,nums[i2]);
        }
    }
    fout2<<res<<endl;
return 0;
}