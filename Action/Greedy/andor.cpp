#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=103;
int cards[MAXN];

vector<int> bits(int num){
    vector<int> res;
    for(int i=0;i<32;++i){
        bool check=(num & (1<<i));
        res.push_back(check);
    }
    return res;
}

vector<int> change(vector<int>& target, vector<int>& curr, int type){
    vector<int> res=curr;
    for(int i=0;i<32;++i){
        if(target[i]==-1 or curr[i]==-1){
            res[i]=-1;
        }else{
            if(type==0){
                if(target[i]==1 or curr[i]==1){
                    res[i]=1;
                }else{
                    res[i]=0;
                }
            }else{
                if(target[i]==0 or curr[i]==0){
                    res[i]=0;
                }else{
                    res[i]=1;
                }
            }
        }
    }
    return res;
}

bool comp(vector<int>& target, vector<int>& curr){
    for(int i=0;i<32;++i){
        if(curr[i]!=target[i]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,g;
    cin>>n>>g;
    for(int i=0;i<n;++i){
        cin>>cards[i];
    }

    vector<int> target=bits(g);
    bool check=false;
    for(int i=n-1;i>=0 and !check;--i){
        vector<int> curr=bits(cards[i]);
        vector<int> or_curr=change(target,curr,0),and_curr=change(target,curr,1);
        
        if(comp(target,or_curr)){
            for(int i2=0;i2<32;++i2){
                if(curr[i2]==1){
                    target[i2]=-1;
                }
            }
        }else if(comp(target,and_curr)){
            for(int i2=0;i2<32;++i2){
                if(curr[i2]==0){
                    target[i2]=-1;
                }
            }
        }
        
        check=true;
        for(int i2=0;i2<32;++i2){
            if(target[i2]==1){
                check=false;
                break;
            }
        }
    }
    cout<<(check ? "Possible" : "Impossible")<<endl;
return 0;
}