// Not solved - 85 points, time limit

#include<iostream>
#include<unordered_map>
#include<array>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,BASE=31;
uint64_t pow_hash[MAXN];

int to_num(char letter){
    return letter-'A'+1;
}

unordered_map<uint64_t, array<int, 2>> make_hashes(int len, string& s1, string& s2){
    unordered_map<uint64_t, array<int, 2>> res;

    uint64_t hash1=0;
    for(int i=0;i<s1.size();++i){
        hash1=hash1*BASE+to_num(s1[i]);
        if(i>=len){
            hash1-=to_num(s1[i-len])*pow_hash[len];
        }
        if(i>=len-1){
            res[hash1]={0, i-len+1};
        }
    }

    uint64_t hash2=0;
    for(int i=0;i<s2.size();++i){
        hash2=hash2*BASE+to_num(s2[i]);
        if(i>=len){
            hash2-=to_num(s2[i-len])*pow_hash[len];
        }
        if(i>=len-1 and res.count(hash2)){
            ++res[hash2][0];
        }
    }

    return res;
}

bool check(int len, int k, string& s1, string& s2){
    auto counter=make_hashes(len, s1, s2);

    for(auto curr : counter){
        if(curr.second[0]>=k){
            return true;
        }
    }

    return false;
}

int calc_res(int len, int k, string& s1, string& s2){
    auto counter=make_hashes(len, s1, s2);

    int ind=-1;
    for(auto curr : counter){
        if(curr.second[0]>=k){
            if(ind==-1){
                ind=curr.second[1];
                continue;
            }
            
            for(int i=0;i<len;++i){
                char letter1=s1[i+ind];
                char letter2=s1[i+curr.second[1]];
                
                if(letter1>letter2){
                    ind=curr.second[1];
                    break;
                }else if(letter1<letter2){
                    break;
                }
            }
        }
    }

    return ind;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pow_hash[0]=1;
    for(int i=1;i<MAXN;++i){
        pow_hash[i]=pow_hash[i-1]*BASE;
    }

    int n,m,k;
    cin>>n>>m>>k;

    string s1,s2;
    cin>>s1>>s2;

    int l=1,r=min(n, m-k+1);
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid, k, s1, s2)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }

    int start_ind=calc_res(r, k, s1, s2);
    for(int i=start_ind;i<start_ind+r;++i){
        cout<<s1[i];
    }
    cout<<endl;
return 0;
}