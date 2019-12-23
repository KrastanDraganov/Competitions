#include<iostream>
#include<vector>
using namespace std;
vector <int> a[100000],ans;
int reb[300000][3],qr[200000][2],b[100000];
int dfs (int vr) {
    int i;
    b[vr]=1;
    for (i=0; i<a[vr].size(); i++) {
        if (b[a[vr][i]]==0) dfs(a[vr][i]);
        }
}
int main () {
    int n,m,q,x,y,i,reb1,reb2,br=0;
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m ;
    for (i=0; i<m; i++) {
        cin >> reb[i][0] >> reb[i][1] ;
        }
    cin >> q ;
    for (i=0; i<q; i++) {
        cin >> qr[i][0] >> qr[i][1] ;
        if (qr[i][0]==1) reb[qr[i][1]-1][2]=1;
        }
    for (i=0; i<m; i++) {
        if (reb[i][2]==0) {
           a[reb[i][0]].push_back(reb[i][1]);
           if (reb[i][0]==1) br++;
           }
        }
    if (br!=0) dfs(1);
    for (i=q-1; i>=0; i--) {
        if (qr[i][0]==1) {
           reb1=reb[qr[i][1]-1][0];
           reb2=reb[qr[i][1]-1][1];
           a[reb1].push_back(reb2);
           if ((b[reb1]==1)&&(b[reb2]==0)) dfs(reb2);
           else if ((reb1==1)&&(b[reb2]==0)) dfs(reb2);
           }
        else ans.push_back(b[qr[i][1]]);
        }
    for (i=ans.size()-1; i>=0; i--) {
        cout << ans[i] << endl ;
        }
    //system ("PAUSE");
    return 0;
}
