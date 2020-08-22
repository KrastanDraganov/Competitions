//Only 55/100 points

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e7+3;
int counter[MAXN];
bool used[MAXN],used2[MAXN];
vector<int> all;

void make_sub(int pos, int curr, int curr_size, int mask, int k, int ind, string s, bool visited){
    if(curr_size>k or pos>=s.size()){
        return;
    }
    
    if(curr_size==k and !used[curr]){
        ++counter[curr];
        used[curr]=true;
        if(!used2[curr]){
            used2[curr]=true;
            all.push_back(curr);
        }
        return;
    }
    
    int letter=s[pos]-'a';
    if(!visited and !(mask & (1<<letter) and curr_size<k)){
        int nexts=curr;
        if(k==1){
            nexts=letter;
        }else if(k<5){
            nexts=100*nexts+letter;
        }else{
            nexts=10*nexts+letter;
        }
        make_sub(pos,nexts,curr_size+1,(mask | (1<<letter)),k,ind,s,true);
    }
    
    make_sub(pos+1,curr,curr_size,mask,k,ind,s,false);
}

string decode(int code, int k){
    string res="";
    if(k==1){
        res=code+'a';
    }else if(k<5){
        while(code>0){
            if(code%100==1){
                
            }
            res+=(code%100)+'a';
            code/=100;
        }
        reverse(res.begin(),res.end());
    }else{
        while(code>0){
            res+=(code%10)+'a';
            code/=10;
        }
        reverse(res.begin(),res.end());
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        make_sub(0,0,0,0,k,i,s,false);
        memset(used,0,sizeof(used));
    }
    
    if(all.empty()){
        cout<<0<<endl;
        return 0;
    }
    
    int max_counter=0,max_counter2=0,res=0;
    for(int curr : all){
        if(counter[curr]>max_counter){
            max_counter=counter[curr];
            res=curr;
            max_counter2=1;
        }else if(max_counter==counter[curr]){
            ++max_counter2;
            if(curr<res){
                res=curr;
            }
        }
    }
    
    cout<<max_counter<<endl<<decode(res,k)<<endl<<max_counter2<<endl;
return 0;
}