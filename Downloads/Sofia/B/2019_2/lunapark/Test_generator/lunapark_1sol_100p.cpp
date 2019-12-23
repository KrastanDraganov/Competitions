#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<time.h>
#include<stack>
using namespace std;
struct dfs_1 { int vr;
               int cnt; };
vector <int> a_1[200001],wht_1[200001],cycle_1[2];
int used_1[200001],fath_1[200001][2],fl_1=0,comp_1[200001],num_1=0,path_1[200001],lens_1[200001],pos_1[200001],top_1[200001],dp_1[200001][21][2],orig_1[200001];
int dfs1_1 (int vr) {
    stack <dfs_1> rec;
    dfs_1 p;
    int i;
    p.vr=vr; p.cnt=0;
    rec.push(p);
    for (;;) {
        if (rec.empty()==1) break;
        if (fl_1!=0) break;
        p=rec.top();
        if (p.cnt==a_1[p.vr].size()) {
           rec.pop(); continue;
           }
        used_1[p.vr]=1;
        for (i=p.cnt; i<a_1[p.vr].size(); i++) {
            rec.top().cnt++;
            if (used_1[a_1[p.vr][i]]==1) {
               if (a_1[p.vr][i]==fath_1[p.vr][0]) continue;
               int cur;
               cur=p.vr;
               for (;;) {
                   cycle_1[0].push_back(cur);
                   if (cur==a_1[p.vr][i]) break;
                   cycle_1[1].push_back(fath_1[cur][1]);
                   cur=fath_1[cur][0];
                   }
               cycle_1[1].push_back(wht_1[p.vr][i]);
               fl_1++;
               rec.pop(); break;
               }
            fath_1[a_1[p.vr][i]][0]=p.vr; fath_1[a_1[p.vr][i]][1]=wht_1[p.vr][i];
            p.vr=a_1[p.vr][i]; p.cnt=0;
            rec.push(p);
            break;
            }
        }
}
int dfs2_1 (int vr, int max1) {
    int i;
    comp_1[vr]=num_1; path_1[vr]=max1;
    used_1[vr]=1;
    for (i=0; i<a_1[vr].size(); i++) {
        if (used_1[a_1[vr][i]]==0) dfs2_1(a_1[vr][i],max(max1,wht_1[vr][i]));
        }
}
int first_solution (char *name1, char *name2) {
    FILE *in=fopen(name1,"r"),*out=fopen(name2,"w");
    int n,m,i,j,x,y,t,prev1,next1,st,q,type,max1[2],len,top1,top2;
    double beg1,end1;
    cout << "first solution: reading the graph started\n";
    beg1=clock();
    fscanf(in,"%d",&n);
    for (i=0; i<n; i++) {
        fscanf(in,"%d%d%d",&x,&y,&t);
        x--; y--;
        a_1[x].push_back(y); wht_1[x].push_back(t);
        a_1[y].push_back(x); wht_1[y].push_back(t);
        orig_1[i]=i;
        }
    cout << "first solution: reading the graph ended\n";
    fath_1[0][0]=-1;
    cout << "first solution: finding the cycle started\n";
    dfs1_1(0);
    cout << "first solution: finding the cycle ended\n";
    memset(used_1,0,sizeof(used_1));
    for (i=0; i<cycle_1[0].size(); i++) {
        used_1[cycle_1[0][i]]=1; pos_1[cycle_1[0][i]]=i;
        }
    for (i=0; i<cycle_1[0].size(); i++) {
        dfs2_1(cycle_1[0][i],-1);
        top_1[num_1]=cycle_1[0][i]; num_1++;
        }
    cout << "first solution: calculating the dp started\n";
    for (i=0; i<cycle_1[0].size(); i++) {
        prev1=(cycle_1[0].size()+i-1)%cycle_1[0].size();
        dp_1[i][0][0]=cycle_1[1][i];
        dp_1[i][0][1]=cycle_1[1][prev1];
        }
    st=1;
    for (i=1; ; i++) {
        st*=2;
        if (st>=cycle_1[0].size()) break;
        for (j=0; j<cycle_1[0].size(); j++) {
            next1=(j+(st/2))%cycle_1[0].size();
            dp_1[j][i][0]=max(dp_1[j][i-1][0],dp_1[next1][i-1][0]);
            }
        for (j=0; j<cycle_1[0].size(); j++) {
            prev1=(cycle_1[0].size()+j-(st/2))%cycle_1[0].size();
            dp_1[j][i][1]=max(dp_1[j][i-1][1],dp_1[prev1][i-1][1]);
            }
        }
    cout << "first solution: calculating the dp ended\n";
    st=1; lens_1[1]=0;
    for (i=2; i<=cycle_1[0].size(); i++) {
        lens_1[i]=lens_1[i-1];
        if (2*st<i) lens_1[i]++, st*=2;
        }
    cout << "first solution: reading and printing queries started\n";
    fscanf(in,"%d",&q);
    for (i=0; i<q; i++) {
        fscanf(in,"%d%d%d",&type,&x,&y);
        x--; y--;
        if (type==1) {
           top1=top_1[comp_1[x]]; top2=top_1[comp_1[y]];
           if (pos_1[top1]>pos_1[top2]) swap(x,y), swap(top1,top2);
           max1[0]=max(path_1[x],path_1[y]);
           len=pos_1[top2]-pos_1[top1];
           max1[0]=max(max1[0],max(dp_1[pos_1[top1]][lens_1[len]][0],dp_1[pos_1[top2]][lens_1[len]][1]));

           max1[1]=max(path_1[x],path_1[y]);
           len=cycle_1[0].size()-(pos_1[top2]-pos_1[top1]);
           max1[1]=max(max1[1],max(dp_1[pos_1[top1]][lens_1[len]][1],dp_1[pos_1[top2]][lens_1[len]][0]));

           if (max1[0]>max1[1]) swap(max1[0],max1[1]);
           fprintf(out,"%d %d\n",max1[0],max1[1]);
           }
        else swap(orig_1[x],orig_1[y]);
        }
    end1=clock();
    cout << "first solution: reading and printing queries ended\n";
    cout << "first solution: ended!!!\n";
    printf("first solution working time: %.2lf s\n",(end1-beg1)/CLOCKS_PER_SEC);
    fclose(in); fclose(out);
    return 0;
}
