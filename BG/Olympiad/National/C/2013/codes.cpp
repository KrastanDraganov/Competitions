#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e4+3,LIMIT=7;
string codes[MAXN];
queue<int> matches[10*MAXN][LIMIT];
bool used[MAXN];
int prefix[11][11];

void precompute(int n, int k){
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            if(i!=i2){
                for(prefix[i][i2]=k-1;prefix[i][i2]>0;--prefix[i][i2]){
                    int curr=prefix[i][i2];
                    bool check=true;
                    for(int i3=0;i3<curr;++i3){
                        if(codes[i][k-curr+i3]!=codes[i2][i3]){
                            check=false;
                        }
                    }
                    if(check){
                        break;
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>codes[i];
    }

    string res="";
    if(n>10){
        for(int i=0;i<n;++i){
            matches[0][0].push(i);
            int curr=0;
            for(int counter=1;counter<k;++counter){
                curr=10*curr+codes[i][counter-1]-'0';
                matches[curr][counter].push(i);
            }
        }
        res=codes[0];
        used[0]=true;
        int prev=0;
        for(int i=1;i<n;++i){
            for(int counter=k-1;counter>=0;--counter){
                string wanted_num=codes[prev].substr(k-counter,counter);
                int curr=(wanted_num.empty() ? 0 : stoi(wanted_num));
                bool check=false;
                while(!matches[curr][counter].empty()){
                    int curr_ind=matches[curr][counter].front();
                    matches[curr][counter].pop();
                    if(!used[curr_ind]){
                        used[curr_ind]=true;
                        prev=curr_ind;
                        check=true;
                        res+=codes[curr_ind].substr(counter,k-counter);
                        break;
                    }
                }
                if(check){
                    break;
                }
            }
        }
    }else{
        precompute(n,k);
        vector<int> pos;
        for(int i=0;i<n;++i){
            pos.push_back(i);
        }
        do{
            int curr=k;
            for(int i=1;i<n;++i){
                curr+=(k-prefix[pos[i-1]][pos[i]]);
            }
            if(res=="" or curr<(int)res.size()){
                res=codes[pos[0]];
                for(int i=1;i<n;++i){
                    res+=codes[pos[i]].substr(prefix[pos[i-1]][pos[i]],k-prefix[pos[i-1]][pos[i]]);
                }
            }
        }while(next_permutation(pos.begin(),pos.end()));
    }
    cout<<res<<endl;
return 0;
}