#include<bits/stdc++.h>
#define N 100005
using namespace std;
unsigned long long a[N],b[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    unsigned long long m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    //sort(a,a+m);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    //sort(b,b+n);
    unsigned long long i=0,i2=0,sum=0,br=0,rez=0;
    while(i<m or i2<n){
        //cout<<i<<" "<<i2<<" "<<br<<" "<<sum<<" "<<rez<<endl;
        if(i<m and i2<n){
            if(b[i2]>a[i]){
                sum+=a[i];
                br++;
                if(sum==b[i2]){
                    rez+=br;
                    sum=0;
                    br=0;
                    i2++;
                    i++;
                }else if(sum>b[i2]){
                    rez+=br;
                    sum=0;
                    br=0;
                    i2++;
                }else{
                    i++;
                }
            }else{
                sum+=b[i2];
                br++;
                if(sum==a[i]){
                    rez+=br;
                    sum=0;
                    br=0;
                    i2++;
                    i++;
                }else if(sum>a[i]){
                    rez+=br;
                    sum=0;
                    br=0;
                    i++;
                }else{
                    i2++;
                }
            }
        }else if(i>=m){
            rez++;
            i2++;
        }else if(i2>=n){
            rez++;
            i++;
        }
    }
    cout<<rez<<endl;
return 0;
}