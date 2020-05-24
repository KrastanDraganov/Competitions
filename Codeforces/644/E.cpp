#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=53;
bool input[MAXN][MAXN],checker[MAXN][MAXN];

bool check(int n){
    for(int i=n-1;i>=0;--i){
        for(int i2=i;i2>=0;--i2){
            if(input[i2][i]){
                if(i==n-1 or (i2<n-1 and checker[i2+1][i]) or (i<n-1 and checker[i2][i+1])){
                    checker[i2][i]=true;
                }else{
                    return false;
                }
            }
        }
        for(int i2=i-1;i2>=0;--i2){
            if(input[i][i2]){ 
                if(i==n-1 or (i<n-1 and checker[i+1][i2]) or checker[i][i2+1]){
                    checker[i][i2]=true;
                }else{
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            for(int i2=0;i2<n;++i2){
                char curr;
                cin>>curr;
                input[i][i2]=curr-'0';
                checker[i][i2]=false;
            }
        }

        cout<<(check(n) ? "YES" : "NO")<<endl;
    }
return 0;
}