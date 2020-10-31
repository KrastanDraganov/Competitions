// Not solved - 60 points, time limit

#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=4e5+3;
int a[MAXN],b[MAXN];

bool is_sol(int n, long long sum, vector<pair<char, int>>& operations){
    if(sum%n!=0){
        return false;
    }

    int target=sum/n;
    if(target!=0){
        operations.push_back({'a', 0-target});
    }

    for(int starti=0;starti<n;++starti){
        bool is_valid=true;
        int ind_a=starti,ind_b=0;

        while(ind_b<n){
            if(a[ind_a]+b[ind_b]!=target){
                is_valid=false;
                break;
            }
            ++ind_a;
            ++ind_b;
            if(ind_a==n){
                ind_a=0;
            }
        }

        if(is_valid){
            if(starti!=0){
                operations.push_back({'r', starti});
            }
            return true;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;

    while(tests--){
        int n;
        cin>>n;

        long long sum=0;
        for(int i=0;i<n;++i){
            cin>>a[i];
            sum+=a[i];
        }
        for(int i=0;i<n;++i){
            cin>>b[i];
            sum+=b[i];
        }

        vector<pair<char, int>> operations;
        if(!is_sol(n, sum, operations)){
            cout<<"-1\n";
        }else{
            cout<<(int)operations.size()<<endl;
            for(pair<char, int> res : operations){
                cout<<res.first<<" "<<res.second<<endl;
            }
        }
    }
return 0;
}