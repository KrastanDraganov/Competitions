#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> graph[MAXN];
int in_degree[MAXN];

vector<int> find_course_order(int n){
    queue<int> prerequisites;
    for(int i=0;i<n;++i){
        if(in_degree[i]==0){
            prerequisites.push(i);
        }
    }

    vector<int> course_order;
    while(!prerequisites.empty()){
        int currv=prerequisites.front();
        prerequisites.pop();

        course_order.push_back(currv);

        for(int nextv : graph[currv]){
            --in_degree[nextv];
            if(in_degree[nextv]==0){
                prerequisites.push(nextv);
            }
        }
    }

    return course_order;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        ++in_degree[to];
    }

    vector<int> res=find_course_order(n);
    if((int)res.size()!=n){
        cout<<"IMPOSSIBLE\n";
    }else{
        for(int course : res){
            cout<<course+1<<" ";
        }
        cout<<endl;
    }
return 0;
}