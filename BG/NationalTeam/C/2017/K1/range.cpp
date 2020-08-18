#include<iostream>
#include<unordered_map>

#define endl '\n'

using namespace std;

const int MAXN=103;
const long long INF=1e18;
long long dist[MAXN][MAXN],counter[MAXN][MAXN];
unordered_map<string,int> decode;

void add_airport(string s, int& airports){
    if(!decode.count(s)){
        decode[s]=airports++;
    }
}

long long find_res(int airports, int limit){
    long long l=1,r=INF;
    while(l<=r){
        long long mid=(l+r)/2;
        for(int i=0;i<airports;++i){
            for(int i2=0;i2<airports;++i2){
                if(dist[i][i2]<=mid){
                    counter[i][i2]=1;
                }else{
                    counter[i][i2]=INF;
                }
            }
        }
        for(int i=0;i<airports;++i){
            for(int i2=0;i2<airports;++i2){
                for(int i3=0;i3<airports;++i3){
                    if(counter[i2][i]+counter[i][i3]<counter[i2][i3]){
                        counter[i2][i3]=counter[i2][i]+counter[i][i3];
                    }
                }
            }
        }
        long long curr=0;
        for(int i=0;i<airports;++i){
            for(int i2=0;i2<airports;++i2){
                curr=max(curr,counter[i][i2]);
            }
        }
        if(curr>limit){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0;i<MAXN;++i){
        for(int i2=0;i2<MAXN;++i2){
            dist[i][i2]=INF;
            counter[i][i2]=INF;
        }
    }
    
    int m,limit;
    cin>>m>>limit;
    int airports=0;
    for(int i=0;i<m;++i){
        string from,to;
        long long weight;
        cin>>from>>to>>weight;
        
        add_airport(from,airports);
        add_airport(to,airports);
        
        int ind1=decode[from],ind2=decode[to];
        dist[ind1][ind2]=weight;
        dist[ind2][ind1]=weight;
        counter[ind1][ind2]=1;
        counter[ind2][ind1]=1;
    }
    
    for(int i=0;i<airports;++i){
        for(int i2=0;i2<airports;++i2){
            for(int i3=0;i3<airports;++i3){
                if(dist[i2][i]+dist[i][i3]<dist[i2][i3]){
                    dist[i2][i3]=dist[i2][i]+dist[i][i3];
                }
            }
        }
    }
    
    cout<<find_res(airports,limit)<<endl;
return 0;
}