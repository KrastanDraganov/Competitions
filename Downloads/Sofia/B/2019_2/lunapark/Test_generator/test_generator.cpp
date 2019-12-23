/* test generator uses testlib.h: https://github.com/MikeMirzayanov/testlib/blob/master/testlib.h
   arguments:
   - first - name of the test that will be generated
   - second - number of vertices
   - third - number of queries
   - fourth - type of the test that will be generated
              = 0 - all queries are of type 1
              = 1 - there are queries of both types
   - (fifth, sixth), seventh, eighth, ... - used for seed for registerGen */
#include<iostream>
#include "testlib.h"
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;
struct edge { int from,to;
              int wht; };
int par[200001],queries[1000001][3],comp[200001],top[200001];
vector <int> perm,cycle,tree,other;
vector <edge> a[200001];
vector <edge> edges;
int main (int argc, char** argv) {
    FILE *out=fopen(argv[1],"w");
    int n,q,state,t,len,root,type,max1=-1,prev1=0,i,j,cnt;
    edge p;
    registerGen(argc,argv,1);
    n=atoi(argv[2]); q=atoi(argv[3]);
    state=atoi(argv[4]);
    for (i=0; i<n; i++) {
        perm.push_back(i);
        }
    cout << "the shuffle started\n";
    shuffle(perm.begin(),perm.end());
    cout << "the shuffle ended\n";
    for (i=0; i<n/2; i++) {
        cycle.push_back(perm[0]);
        perm.erase(perm.begin());
        }
    for (i=0; i<cycle.size(); i++) { //cout << cycle[i] << " ";
        p.wht=rnd.wnext(1,int(1e6),-2);
        p.to=cycle[(i+1)%cycle.size()]; a[cycle[i]].push_back(p);
        p.to=cycle[i]; a[cycle[(i+1)%cycle.size()]].push_back(p);
        max1=max(max1,p.wht);
        }
    cout << "generating trees started\n";
    for (cnt=1; ; cnt++) {
        if (perm.empty()==1) break;
        len=min(max(rnd.next((n/2)/1000,(n/2)/100),1),int(perm.size()));
        root=cycle[rnd.next(cycle.size())];
        tree.clear(); tree.push_back(root);
        comp[root]=cnt; top[cnt]=root;
        for (i=0; i<len; i++) {
            tree.push_back(perm[0]); other.push_back(perm[0]);
            comp[perm[0]]=cnt;
            perm.erase(perm.begin());
            par[i+1]=rnd.wnext(i+1,10);
            }
        shuffle(tree.begin()+1,tree.end());
        for (i=1; i<=len; i++) {
            type=rnd.wnext(2,-2);
            if (type==0) p.wht=rnd.wnext(1,max1/2,-5);
            else p.wht=rnd.wnext(max1/2,11*max1/10,5);
            p.to=tree[i]; a[tree[par[i]]].push_back(p);
            p.to=tree[par[i]]; a[tree[i]].push_back(p);
            }
        }
    for (i=0; i<cycle.size(); i++) {
        if (comp[cycle[i]]==0) {
           comp[cycle[i]]=cnt;
           top[cnt]=cycle[i];
           cnt++;
           }
        }
    cout << "generating trees ended\n";
    cout << "generating queries started\n";
    for (i=0; i<q; i++) {
        if (prev1==1) type=0;
        else type=rnd.wnext(2,-2);
        if ((type==0)||(state==0)) {
           queries[i][0]=1;
           type=rnd.next(2);
           if (type==0) queries[i][1]=other[rnd.next(other.size())];
           else queries[i][1]=cycle[rnd.next(cycle.size())];
           type=rnd.next(2);
           for (;;) {
               if (type==0) queries[i][2]=other[rnd.next(other.size())];
               else queries[i][2]=cycle[rnd.next(cycle.size())];
               if (top[comp[queries[i][1]]]!=top[comp[queries[i][2]]]) break;
               }
           //if ((i<2000)&&(queries[i][1]==41)&&(queries[i][2]==127)) cout << comp[queries[i][1]] << " " << comp[queries[i][2]] << endl ;
           }
        else { queries[i][0]=2;
               queries[i][1]=cycle[rnd.next(cycle.size())];
               for (;;) {
                   queries[i][2]=cycle[rnd.next(cycle.size())];
                   if (top[queries[i][1]]!=top[queries[i][2]]) break;
                   }
               swap(comp[queries[i][1]],comp[queries[i][2]]);
               swap(top[queries[i][1]],top[queries[i][1]]); }
        prev1=queries[i][0]-1;
        }
    cout << "generating queries ended\n";
    cout << "shuffling edges started\n";
    for (i=0; i<n; i++) {
        for (j=0; j<a[i].size(); j++) {
            if (i>a[i][j].to) continue;
            a[i][j].from=i;
            edges.push_back(a[i][j]);
            }
        }
    shuffle(edges.begin(),edges.end());
    cout << "shuffling edges ended\n";
    cout << "printing test started\n";
    fprintf(out,"%d\n",n);
    for (i=0; i<edges.size(); i++) {
        if (rnd.next(2)==0) swap(edges[i].from,edges[i].to);
        fprintf(out,"%d %d %d\n",edges[i].from+1,edges[i].to+1,edges[i].wht);
        }
    fprintf(out,"%d\n",q);
    for (i=0; i<q; i++) {
        fprintf(out,"%d %d %d\n",queries[i][0],queries[i][1]+1,queries[i][2]+1);
        }
    cout << "printing test ended\n";
    cout << "test successfully generated!!!\n";
    fclose(out);
    return 0;
}
