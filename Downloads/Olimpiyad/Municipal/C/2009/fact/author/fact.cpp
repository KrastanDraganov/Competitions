#include <cstdio>

const int max=10000;
int N;
int a[max+1];

int main()
{
  scanf("%d",&N);
  for(int i=2;i<=N;i++)
  {
    
	int v=i;
	int j=2;
	while(v>1)
	{
	  while(v%j==0) {v /=j; a[j]++;} 
	  j++;
	}
  }  

  int c=0;
  for(int i=1;i<=max;i++) c += a[i];
  printf("%d\n",c);

}


