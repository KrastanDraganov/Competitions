#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
vector<int> graph[MAXN];
int weights[MAXN];

int dfs(int currv, int parent, int target, vector<int>& res){
   int sum=weights[currv];
   for(int nextv : graph[currv]){
       if(nextv!=parent){
           sum+=dfs(nextv,currv,target,res);
       }
   }
   if(sum==target){
       res.push_back(currv+1);
       sum=0;
   }
   return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    int root=-1,sum=0;
    for(int i=0;i<n;++i){
        int parent;
        cin>>parent>>weights[i];
        --parent;
        if(parent==-1){
            root=i;
        }else{
            graph[parent].push_back(i);
        }
        sum+=weights[i];
    }

    vector<int> res;
    dfs(root,-1,sum/3,res);
    if((int)res.size()<3 or sum%3!=0){
        cout<<-1<<endl;
    }else{
        cout<<res[0]<<" "<<res[1]<<endl;
    }
return 0;
}