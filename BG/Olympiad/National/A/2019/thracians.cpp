#include<iostream>

#define endl '\n'

using namespace std;
const int MAXN=5e3+3,BASE=31,MAXR=103;
unsigned long long hash_table[MAXR][MAXN],pow_n[MAXN],pow_r[MAXR];

int ind(int row, int mod){
    if(row<0){
        row+=mod;
    }

    return row%mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pow_r[0]=1;
    for(int i=1;i<MAXR;++i){
        pow_r[i]=pow_r[i-1]*BASE;
    }

    pow_n[0]=1;
    for(int i=1;i<MAXN;++i){
        pow_n[i]=pow_n[i-1]*BASE;
    }

    int r,c;
    cin>>r>>c;

    unsigned long long hash_word=0;
    for(int i=0;i<r;++i){
        unsigned long long hash_row=0;
        for(int i2=0;i2<c;++i2){
            char curr;
            cin>>curr;
            hash_row+=(curr-'a'+1)*pow_r[i2];
        }
        hash_word+=hash_row*pow_r[i];
    }

    int n,m;
    cin>>n>>m;

    int res=0;
    for(int i=1;i<=n;++i){
        int row=ind(i, r+1);
        int prev=(row==0 ? r : row-1);
        
        unsigned long long hash_row=0;
        for(int col=1;col<=m;++col){
            char curr;
            cin>>curr;
            
            hash_row+=(curr-'a'+1)*pow_n[col-1];
            hash_table[row][col]=hash_table[prev][col]+pow_n[i-1]*hash_row;

            if(i<r or col<c){
                continue;
            }

            int limit=ind(row-r, r+1);
            unsigned long long comp_hash=hash_table[row][col]-hash_table[limit][col]-hash_table[row][col-c]+hash_table[limit][col-c];
            if(comp_hash==hash_word*pow_n[i-r]*pow_n[col-c]){
                ++res;
            }
        }
    }
    
    cout<<res<<endl;
return 0;
}