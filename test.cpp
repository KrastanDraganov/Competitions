#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1003;
vector<int> graph[MAXN];
int lca[MAXN][32];

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int tests;
   cin>>tests;
   while(tests--){
      int n;
      cin>>n;
      for(int i=0;i<n;++i){
         int children;
         cin>>children;
         for(int i2=0;i2<children;++i2){
            int to;
            cin>>to;
            graph[i].push_back(to);
            graph[to].push_back(i);
         }
      }
   }

return 0;
}