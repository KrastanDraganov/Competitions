//Task comp
//Author Pano Panov
#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <string.h>
#define MAX_SONGS 64
#define MAX_COMPS 100008

using namespace std;

int cs[MAX_COMPS][3];
int clist[MAX_SONGS][2];
int maxarr[MAX_SONGS], maxfirst[MAX_SONGS];
int N, M, total;

bool gt(int x, int y){ return(x>y); }
bool lt(int x, int y){ return(x<y); }

void InputData(){
    int i, j, k;
    char buf[20];
    memset(cs, 0, sizeof(cs));
    memset(clist, 0, sizeof(clist)) ;
    cin>>N;
    for(i=0; i<N; i++){
        cin>>buf;
        for(j=k=0; buf[j]; j++){
            if(buf[j] == 'S'){ cs[i][k++] = atoi(&buf[j+1]);}
        }
    }
}
void RemoveLast(int v){
 int i;
 for(i=0; i<N; i++){
    if(cs[i][0] == 0) continue;
    if(cs[i][0] == v){
       cs[i][0] = cs[i][1];
       cs[i][1] = cs[i][2];
       cs[i][2] = 0;
    }
    else{
         if(cs[i][1] == v) {
            cs[i][1] = cs[i][2];
            cs[i][2] = 0;
         }
         else{
            if(cs[i][2] == v) {
               cs[i][2] = 0;
            }
         }
    }
 }
}
void CreateList(){
     int i, j;
     memset(clist, 0, sizeof(clist));
     for(i=0; i<N; i++){
         if(cs[i][0] == 0)continue;
         for(j=0; j<3; j++){
             if(cs[i][j]>0){
                clist[cs[i][j]][0] = 1;
                if(j == 0)(clist[cs[i][j]][1])++;
             }
         }
     }
     M = MAX_SONGS - 1;
     while(clist[M][0] == 0) M--;
     if(maxfirst[0]==0){
        for(i=1; i<=M; i++){ maxfirst[i] = clist[i][1];}
        maxfirst[0] = 1;
     }
}

int MiniMax(int vmax, bool (*fct)(int, int)){
   int i, nmax;
   memset(maxarr, 0, sizeof(maxarr));
   total = 0;
   CreateList();
   for(i=1; i<=M; i++){
       total += clist[i][1];
       if(clist[i][0]>0 && fct(clist[i][1], vmax)) vmax = clist[i][1];
   }
   nmax = 0;
   for(i=1; i<=M; i++){
       if(clist[i][1]==vmax){
          maxarr[nmax++] = i;
       }
   }
   total -= vmax;
   return nmax;
}
bool IsParity(){
     int i, j, w;
     i = 1;
     while(clist[i][0]==0)i++;
     w = clist[i][1];
     for(j=i+1; j<=M; j++){
        if(clist[j][0]==0) continue;
        if(clist[j][1]!=w){
          return false;
        }
     }
     return true;
}

int main()
{
    int i, j;
    memset(maxfirst, 0, sizeof(maxfirst));
    InputData();
    while(true){
             j = MiniMax(-1, gt);
             if((j == 1)&&(clist[maxarr[0]][1]>total)){
                cout<<"S"<<maxarr[0]<<" "<<maxfirst[maxarr[0]]<<endl;
                break;
             }
             else{
                  if(IsParity()){
                    bool flg = false;
                    for(i=1; i<=M; i++){
                        if(flg)cout<<" ";
                        if(clist[i][0] > 0){cout<<"S"<<i; flg = true;}
                    }
                   cout<<endl;
                   break;
                  }
                  else{
                       j = MiniMax(MAX_COMPS, lt);
                       for(i=0; i<j; i++){
                           RemoveLast(maxarr[i]);
                      }
                  }
             }
    };
    return 0;
}
/* End of File */

