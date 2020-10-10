#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3,BASE=200131;
int a[MAXN],b[MAXN];
unsigned long long hash_a[MAXN],pow_n[2*MAXN];
unordered_map<int, int> compressor;

int compress(int num, int& counter){
    if(!compressor.count(num)){
        compressor[num]=counter++;
    }
    return compressor[num];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pow_n[0]=1;
    for(int i=1;i<MAXN;++i){
        pow_n[i]=pow_n[i-1]*BASE;
    }

    int n,m,p;
    cin>>n>>m>>p;

    int counter=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        a[i]=compress(a[i], counter);
    }

    unsigned long long hash_b=0;
    for(int i=0;i<m;++i){
        cin>>b[i];
        b[i]=compress(b[i], counter);
        hash_b+=pow_n[b[i]];
    }

    vector<int> res;
    for(int starti=0;starti<p;++starti){
        for(int i=starti;i<n;i+=p){
            hash_a[i]=pow_n[a[i]];
            if(i>=p){
                hash_a[i]+=hash_a[i-p];
            }

            unsigned long long curr_hash=hash_a[i];
            if((long long) i>=(long long) m*p){
                curr_hash-=hash_a[i-m*p];
            }

            if(curr_hash==hash_b){
                res.push_back(i-(m-1)*p);
            }
        }
    }

    sort(res.begin(), res.end());
    cout<<(int) res.size()<<endl;
    for(int curr : res){
        cout<<curr+1<<" ";
    }
    cout<<endl;
return 0;
}