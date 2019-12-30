#include <iostream>
#include <stdlib.h>     /* qsort */

#define MAX_N 10000
#define MAX_EDGE 70001
#define MIN_Y 0
#define MAX_Y 30000

using namespace std;

int edge[MAX_EDGE];
int sum[MAX_EDGE];
int e[2*MAX_N][4]; //(x,y0,y1,flag=+-1)
long long en;
int n;
long long area;

static int comp(const void* p1, const void* p2) {
  int* arr1 = (int*)p1;
  int* arr2 = (int*)p2;
  int diff1 = arr1[0] - arr2[0];
  if (diff1) return diff1;
  return arr1[3] - arr2[3];
}
void inpData(){
    int i, x1,x2,y1,y2;
    cin>>n;
    en = 0;
    for(i=1; i<=n; i++){
        cin>>x1>>y1>>x2>>y2;
        e[en][0]=x1;
        e[en][1]=y1;
        e[en][2]=y2;
        e[en][3]=1;
        en++;
        e[en][0]=x2;
        e[en][1]=y1;
        e[en][2]=y2;
        e[en][3]=-1;
        en++;
    }
}// End of Read_data
void correct(long long v,long long min_value,long long max_value){
if((edge[v]==0) && (min_value<max_value))
      sum[v]=sum[2*v]+sum[2*v+1];
}
void add(long long v, int min_value, int max_value, int y0, int y1, int delta ){
int tmp, res;
if((y0<=min_value) && (max_value<=y1)){
      res=(max_value+1-min_value)*delta;
      if(delta>0){
        edge[v]=edge[v]+delta;
        sum[v]=res;
      }else{
            edge[v]=edge[v]+delta;
            if(edge[v]==0){
               sum[v]=0;
               correct(v,min_value,max_value);
            }
      }
} else if(min_value<max_value){
         tmp=(min_value+max_value)/2;
         res=0;
         if(y0<=tmp) add(2*v,min_value,tmp,y0,y1,delta);
         if((tmp<y1) && (tmp<max_value))
	       add(2*v+1,tmp+1,max_value,y0,y1,delta);
         correct(v,min_value,max_value);
   }
}
void new_edge(int y0, int y1, int delta){
   add(1,MIN_Y,MAX_Y,y0,y1-1,delta);
}
void calcArr(){
int i;
   for(i=0; i<MAX_EDGE; i++){
        edge[i] = sum[i] = 0;
   }
   area=0;
   qsort (e, en,4*sizeof(int), comp);
   for(i=0; i< en; i++ ) {
      if((i>0) && (e[i][0] != e[i-1][0])) {
        area=area+(sum[1]*(e[i][0]-e[i-1][0]));
	  }
	  if(i==en-1) cout<<sum[1]<<" "<<e[i-1][1]<<" "<<e[i-1][2]<<" "<<e[i-1][3]<<endl;
      new_edge(e[i][1],e[i][2],e[i][3]);
   }
} // End of calcArr
int main(){
 inpData();
 calcArr();
 cout<<area<<endl;
 return 0;
}
// End of File
