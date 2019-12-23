//Task: report
//Author: Kinka Kirilowa-Lupanowa

#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> p(n + 1);
  p[0] = -1;
  stack<int> st;
  st.push(0);
  for (int i = 1; i <= n; i++)
   {
    scanf("%d", &p[i]);
    while (p[i] <= p[st.top()]) 
      st.pop();
    printf("%d ", st.top());
    st.push(i);
  }
  
  printf("\n");
   return 0;
}

