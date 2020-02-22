#include<iostream>
#define endl '\n'
using namespace std;
const int MAXN=1003;
int cards[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cards[0][i]=i+1;
    }
    int pos,counter=0;
    while(cin>>pos){
        int l=0,r=pos;
        ++counter;
        for(int i=0;i<n;++i){
            if((i%2==0 and l<pos)or r>=n){
                cards[counter][i]=cards[counter-1][l++];
            }else{
                cards[counter][i]=cards[counter-1][r++];
            }
        }
    }
    for(int i=0;i<n;++i){
        cout<<cards[counter][i]<<" ";
    }
    cout<<endl;
return 0;
}