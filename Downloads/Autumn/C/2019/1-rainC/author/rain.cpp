#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int nMax = 1000000;

long long int H[nMax];
int max_dH[nMax]={0};
vector <int> LR;
vector <int> RL;

int n, dn;
int KL, KR;
int countB=0;
long long int volume=0;
int L=-1, R=-1;

void input() {
  int j, dH;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
      scanf("%d",&H[i]);
  scanf("%d",&dn);
  for (int i=0;i<dn;i++){
      scanf("%d %d",&j, &dH);
      max_dH[j]=dH;
      H[j]=H[j]+dH;
  }
}

void scan() {
  KL=0;
  for (int i=1;i<n;i++)
      if (H[KL]<H[i]){
        L=KL;
        LR.push_back(KL);
        KL=i;
      }
  KR=n-1;
  for (int i=n-2;i>=KL;i--)
      if (H[KR]<H[i]){
        R=KR;
        RL.push_back(KR);
        KR=i;
      }
}

void solve() {
   int HLmax, HRmax;
   if (LR.size()>0){
       LR.push_back(KL);
       for (int i=0;i<LR.size()-1;i++){
          if (max_dH[LR[i]]>0) countB++;
          volume = volume+(H[LR[i]]*(LR[i+1]-LR[i]));
       }
   }
   if (RL.size()>0){
       RL.push_back(KR);
       for (int i=0;i<RL.size()-1;i++){
          if (max_dH[RL[i]]>0) countB++;
          volume = volume+(H[RL[i]]*(RL[i]-RL[i+1]));
       }
   }

   if (KL<KR){
       if(max_dH[KL]>0) countB++;
       if(max_dH[KR]>0) countB++;
       volume = volume+(H[KL]*(KR-KL));
   }
   else {
       if (L==-1)
          HLmax = 0;
       else
          HLmax = H[L];
       if (R==-1)
          HRmax = 0;
       else
          HRmax = H[R];
       if (HLmax != HRmax){
          if ((H[KL]-max_dH[KL]) < max(HRmax,HLmax)) countB++;
       }
   }
}

int main() {
  input();
  scan();
  solve();

  //printf ("%d %I64d\n", countB, volume);

  printf ("%d %lld\n", countB, volume);
}

/*
6
2 4 2 4 2 1
2
2 1
4 1
*/

/*
10
1 2 3 4 5 6 7 8 9 10
3
0 9
4 5
7 2
*/

/*
6
1 3 2 2 4 2
2
2 4
5 3
*/

