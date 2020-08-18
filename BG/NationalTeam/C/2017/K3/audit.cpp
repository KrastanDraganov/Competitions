#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
vector<int> graph[MAXN],leaves;
int chief[MAXN],salary[MAXN],added[MAXN];
pair<int,int> coeff[MAXN];

void dfs(int currv, int parent, int bonus){
    salary[currv]+=bonus;
    added[currv]=0;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dfs(nextv,currv,bonus+added[nextv]);
        }
    }
}

void update_coeff(int n){
    for(int i=0;i<n;++i){
        coeff[i]={salary[i],salary[i]};
    }
    for(int currv : leaves){
        while(currv!=0){
            int nextv=chief[currv];
            coeff[nextv].first=max(coeff[currv].first,coeff[nextv].first);
            coeff[nextv].second=min(coeff[currv].second,coeff[nextv].second);
            currv=nextv;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=1;i<n;++i){
        int parent;
        cin>>parent;
        --parent;
        graph[parent].push_back(i);
        graph[i].push_back(parent);
        chief[i]=parent;
    }
    for(int i=0;i<n;++i){
        cin>>salary[i];
    }

    for(int i=1;i<n;++i){
        if((int)graph[i].size()==1){
            leaves.push_back(i);
        }
    }
    
    int q;
    cin>>q;
    bool is_change=false;
    update_coeff(n);
    while(q--){
        char type;
        int person;
        cin>>type>>person;
        --person;
        if(type=='R'){
            int new_salary;
            cin>>new_salary;
            added[person]+=new_salary;
            is_change=true;
        }else{
            if(is_change){
                dfs(0,-1,added[0]);
                update_coeff(n);
                is_change=false;
            }
            cout<<coeff[person].first-coeff[person].second<<endl;
        }
    }
return 0;
}