#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;
long long N, a[1000003], mst, mind, ans, table[1000003], ans1, Q, c, uv, br, ind[1000003];
int main() {
    cin>>N;
    cin>>a[0];
    table[0]=a[0];
    mst=a[0];
    for(int i=1; i<N; i++){
        cin>>a[i];
        if(mst<a[i]){
            mst=a[i];
            mind=i;
        }
        else{
            for(int j=mind; j<i; j++){
                if(table[j]<a[i]){
                    table[j]=a[i];
                }
            }
        }
        ind[i]=mind;
    }
    for(int i=0; i<N; i++){
        ans+=table[i];
    }
    cin>>Q;
    for(int q=0; q<Q; q++){
        ans1=ans;
        cin>>c>>uv;
        if(table[c-1]<(a[c]+uv) or table[c-1]<(a[c]+uv)){
                cout<<c<<" "<<ind[c]<<endl;
            for(int i=ind[c]; i<c; i++){
                if(table[i]<(a[c]+uv)){
                    ans1-=table[i];
                    ans1+=a[c]+uv;
                }

            }
            /*a[c]+=uv;
            ans1+=a[0];
            mst=0;
            mind=0;
            for(int i=1; i<N; i++){
                if(mst<a[i]){
                    mst=a[i];
                    mind=i;
                }
                else{
                    for(int j=mind; j<i; j++){
                        if(table[j]<a[i]){
                            table[j]=a[i];
                        }
                    }
                }
            }
            for(int i=0; i<N; i++){
                ans1+=table[i];
            }*/
            if(ans1>ans){
                br++;
                ans=ans1;
            }
        }
    }
    cout<<br<<" "<<ans;
    return 0;
}
/*
6
2 4 2 4 2 1
2
2 1
4 1
*/
