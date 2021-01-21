#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MOD=1e9+7;

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

int mul_mod(int x, int y){
    return 1ll*x*y%MOD;
}

void put_back(int& num1, int num2){
    num1*=10;
    if(num2>9){
        num1*=10;
    }
    num1+=num2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    int fact=1;
    for(int i=1;i<=n-4;++i){
        fact=mul_mod(fact, i);
    }

    int res=0;
    for(int i=1;i<=n;++i){
        for(int i2=1;i2<=n;++i2){
            for(int i3=1;i3<=n;++i3){
                for(int i4=1;i4<=n;++i4){
                    if(i==i2 or i==i3 or i==i4 or i2==i3 or i2==i4 or i3==i4){
                        continue;
                    }

                    int curr=i;
                    put_back(curr, i2);
                    put_back(curr, i3);
                    put_back(curr, i4);

                    if(curr%16==0){
                        add_mod(res, fact);
                    }
                }
            }
        }
    }

    cout<<res<<endl;
return 0;
}