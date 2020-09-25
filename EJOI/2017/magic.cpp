#include<iostream>
#include<string>
#include<set>
#include<unordered_map>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,ALPHABET=2*26,BASE=31,MOD=1e9+7;

int prefix[ALPHABET][MAXN];

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

void calc_prefix(int ind, char letter1, char letter2, int n, string& s){
    for(int i=0;i<n;++i){
        int curr=0;
        
        if(s[i]==letter1){
            curr=1;
        }else if(s[i]==letter2){
            curr=-1;
        }
        
        prefix[ind][i+1]=prefix[ind][i]+curr;
    }
}

unsigned long long make_hash(int ind, int k){
    unsigned long long res=0;
    
    for(int i=0;i<k-1;++i){
        res=res*BASE+prefix[i][ind]+1;
    }

    return res;
}

int magic_substrings(int n, string& s){
    set<char> all_letters;
    for(char curr : s){
        all_letters.insert(curr);
    }

    int k=(int) all_letters.size();
    if(k==1){
        return n;
    }

    auto it=all_letters.begin();
    char letter1=*it;
    ++it;

    for(int i=0; it!=all_letters.end() ;++i){
        char letter2=*it;
        ++it;

        calc_prefix(i, letter1, letter2, n, s);

        letter1=letter2;
    }

    unordered_map<unsigned long long, int> prev;
    unsigned long long start_hash=0;
    for(int i=0;i<k-1;++i){
        start_hash=start_hash*BASE+1;
    }
    ++prev[start_hash];

    int res=0;
    for(int i=0;i<n;++i){
        unsigned long long curr_hash=make_hash(i+1,k);
        add_mod(res,prev[curr_hash]);
        ++prev[curr_hash];
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin>>n>>s;

    cout<<magic_substrings(n,s)<<endl;
return 0;
}