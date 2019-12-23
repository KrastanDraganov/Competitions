#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<time.h>
#include<stack>
using namespace std;
struct dfs_2 { int vr;
               int cnt; };
vector <int> a_2[200001],wht_2[200001],cycle_2[2];
int used_2[200001],fath_2[200001][2],fl_2=0,comp_2[200001],num_2=0,path_2[200001],pos_2[200001],top_2[200001],dp_2[200001][21][2],orig_2[200001];
int dfs1_2 (int vr) {
    stack <dfs_2> rec;
    dfs_2 p;
    int i;
    p.vr=vr; p.cnt=0;
    rec.push(p);
    for (;;) {
        if (rec.empty()==1) break;
        if (fl_2!=0) break;
        p=rec.top();
        if (p.cnt==a_2[p.vr].size()) {
           rec.pop(); continue;
           }
        used_2[p.vr]=1;
        for (i=p.cnt; i<a_2[p.vr].size(); i++) {
            rec.top().cnt++;
            if (used_2[a_2[p.vr][i]]==1) {
               if (a_2[p.vr][i]==fath_2[p.vr][0]) continue;
               int cur;
               cur=p.vr;
               for (;;) {
                   cycle_2[0].push_back(cur);
                   if (cur==a_2[p.vr][i]) break;
                   cycle_2[1].push_back(fath_2[cur][1]);
                   cur=fath_2[cur][0];
                   }
               cycle_2[1].push_back(wht_2[p.vr][i]);
               fl_2++;
               rec.pop(); break;
               }
            fath_2[a_2[p.vr][i]][0]=p.vr; fath_2[a_2[p.vr][i]][1]=wht_2[p.vr][i];
            p.vr=a_2[p.vr][i]; p.cnt=0;
            rec.push(p);
            break;
            }
        }
}
int dfs2_2 (int vr, int max1) {
    int i;
    comp_2[vr]=num_2; path_2[vr]=max1;
    used_2[vr]=1;
    for (i=0; i<a_2[vr].size(); i++) {
        if (used_2[a_2[vr][i]]==0) dfs2_2(a_2[vr][i],max(max1,wht_2[vr][i]));
        }
}
int second_solution (char *name1, char *name2) {
    FILE *in=fopen(name1,"r"),*out=fopen(name2,"w");
    int n,m,i,j,x,y,t,prev1,next1,st,q,type,max1[2],len,top1,top2,ind;
    double beg1,end1;
    cout << "second solution: reading the graph started\n";
    beg1=clock();
    fscanf(in,"%d",&n);
    for (i=0; i<n; i++) {
        fscanf(in,"%d%d%d",&x,&y,&t);
        x--; y--;
        a_2[x].push_back(y); wht_2[x].push_back(t);
        a_2[y].push_back(x); wht_2[y].push_back(t);
        orig_2[i]=i;
        }
    cout << "second solution: reading the graph ended\n";
    fath_2[0][0]=-1;
    cout << "second solution: finding the cycle started\n";
    dfs1_2(0);
    cout << "second solution: finding the cycle ended\n";
    memset(used_2,0,sizeof(used_2));
    for (i=0; i<cycle_2[0].size(); i++) {
        used_2[cycle_2[0][i]]=1; pos_2[cycle_2[0][i]]=i;
        }
    for (i=0; i<cycle_2[0].size(); i++) {
        dfs2_2(cycle_2[0][i],-1);
        top_2[num_2]=cycle_2[0][i]; num_2++;
        }
    cout << "second solution: calculating the dp started\n";
    for (i=0; i<cycle_2[0].size(); i++) {
        prev1=(cycle_2[0].size()+i-1)%cycle_2[0].size();
        dp_2[i][0][0]=cycle_2[1][i];
        dp_2[i][0][1]=cycle_2[1][prev1];
        }
    st=1;
    for (i=1; ; i++) {
        st*=2;
        if (st>=cycle_2[0].size()) break;
        for (j=0; j<cycle_2[0].size(); j++) {
            next1=(j+(st/2))%cycle_2[0].size();
            dp_2[j][i][0]=max(dp_2[j][i-1][0],dp_2[next1][i-1][0]);
            }
        for (j=0; j<cycle_2[0].size(); j++) {
            prev1=(cycle_2[0].size()+j-(st/2))%cycle_2[0].size();
            dp_2[j][i][1]=max(dp_2[j][i-1][1],dp_2[prev1][i-1][1]);
            }
        }
    cout << "second solution: calculating the dp ended\n";
    cout << "second solution: reading and printing queries started\n";
    fscanf(in,"%d",&q);
    for (i=0; i<q; i++) {
        fscanf(in,"%d%d%d",&type,&x,&y);
        x--; y--;
        if (type==1) {
           top1=top_2[comp_2[x]]; top2=top_2[comp_2[y]];
           if (pos_2[top1]>pos_2[top2]) swap(x,y), swap(top1,top2);
           max1[0]=max(path_2[x],path_2[y]);
           len=pos_2[top2]-pos_2[top1];
           st=1; ind=0;
           for (;;) {
               if (2*st>len) break;
               st*=2; ind++;
               }
           max1[0]=max(max1[0],max(dp_2[pos_2[top1]][ind][0],dp_2[pos_2[top2]][ind][1]));

           max1[1]=max(path_2[x],path_2[y]);
           len=cycle_2[0].size()-(pos_2[top2]-pos_2[top1]);
           st=1; ind=0;
           for (;;) {
               if (2*st>len) break;
               st*=2; ind++;
               }
           max1[1]=max(max1[1],max(dp_2[pos_2[top1]][ind][1],dp_2[pos_2[top2]][ind][0]));

           if (max1[0]>max1[1]) swap(max1[0],max1[1]);
           fprintf(out,"%d %d\n",max1[0],max1[1]);
           }
        else swap(orig_2[x],orig_2[y]);
        }
    end1=clock();
    cout << "second solution: reading and printing queries ended\n";
    cout << "second solution: ended!!!\n";
    printf("second solution working time: %.2lf s\n",(end1-beg1)/CLOCKS_PER_SEC);
    fclose(in); fclose(out);
    return 0;
}
