#include<iostream>
#include<string>
#include<set>
#include<unordered_map>

#define endl '\n'

using namespace std;

const int MAXN1=2e3+3,MAXN2=1e5+3,ALPHABET=2*26,MOD=1e9+7;

int counter[MAXN1][ALPHABET];
int prefix[MAXN2];

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

int letter_code(char letter){
    if(letter>='a' and letter<='z'){
        return letter-'a'+1;
    }
    return letter-'A'+26+1;
}

int subtask2(int n, string& s){
    set<int> all_letters;
    for(int i=0;i<n;++i){
        int curr_code=letter_code(s[i]);

        for(int i2=0;i2<ALPHABET;++i2){
            counter[i+1][i2]=counter[i][i2];
        }
        ++counter[i+1][curr_code-1];

        all_letters.insert(curr_code);
    }

    int res=0;
    int k=(int) all_letters.size();

    for(int len=k;len<=n;len+=k){
        int curr=0;
        int target=len/k;
        
        for(int i=0;i+len-1<n;++i){

            bool is_magic=true;
            for(int i2=0;i2<ALPHABET;++i2){
                int diff=counter[i+len][i2]-counter[i][i2];
                is_magic &= (!diff or diff==target);
            }

            curr+=is_magic;
        }
        
        add_mod(res,curr);
    }
    
    return res;
}

int subtask3(int n, string& s){
    unordered_map<int,int> prev;
    ++prev[0];

    char target=s[0];
    prefix[1]=1;
    ++prev[1];

    int res=0;
    for(int i=1;i<n;++i){
        prefix[i+1]=prefix[i]+(target==s[i] ? 1 : -1);
        add_mod(res,prev[prefix[i+1]]);
        ++prev[prefix[i+1]];
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin>>n>>s;

    
    if(n<MAXN1){
        cout<<subtask2(n,s)<<endl;
    }else{
        cout<<subtask3(n,s)<<endl;
    }
return 0;
}