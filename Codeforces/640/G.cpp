#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1003;
bool used[MAXN];
int res[MAXN];

bool check(int diff){
    return 1<diff and diff<5;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        
        for(int i=0;i<n;++i){
            used[i]=false;
        }
        int curr=n,prev=-1,counter=0;
        while(curr!=prev){
            res[counter++]=curr;
            used[curr]=true;
            prev=curr;
            for(int i=4;i>=2;--i){
                if(curr+i<=n and !used[curr+i]){
                    curr+=i;
                    break;
                }else if(curr-i>0 and !used[curr-i]){
                    curr-=i;
                    break;
                }
            }
        }
        if(counter==n-1){
            int target=-1;
            for(int i=1;i<=n;++i){
                if(!used[i]){
                    target=i;
                    break;
                }
            }
            int ind=-1;
            for(int i=0;i<n;++i){
                if((i==0 and check(abs(target-res[0])))
                    or (i==n-1 and check(abs(target-res[n-2])))
                    or (check(abs(target-res[i])) and check(abs(target-res[i-1])))){
                    ind=i;
                    break;
                }
            }
            if(ind>-1){
                ++counter;
                for(int i=n-1;i>ind;--i){
                    res[i]=res[i-1];
                }
                res[ind]=target;
            }
        }
        if(counter<n){
            cout<<-1<<endl;
        }else{
            for(int i=0;i<n;++i){
                cout<<res[i]<<" ";
            }
            cout<<endl;
        }
    }
return 0;
}