#include<iostream>
#include<stack>
#define endl '\n'
using namespace std;
int m[1000005],pr,h,m2[1000005];
stack<int> st;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,in,h,mv=0,br=0;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>m[i];
        m2[i]=m[i];
    }

    st.push(0);
    for(int i=0;i<n;i++){
           int  j=1;
        while(m[j]!=m[st.top()])
       {
         if(m[j]>m[st.top()])
        {
            st.pop();
            st.push(j);
        }
        else
        {
            m[j]=m[st.top()];
        }
        j++;
       }

    }

    cin>>k;
    int ob=0;
    for(int i=0;i<k;i++)
    {
        cin>>pr>>h;
        if(m2[pr]+h>m[pr])
        {
           br++;
           while(!st.empty()) st.pop();
           m[pr]=m2[pr]+h;
           st.push(pr);
           int j=i+1;
            while(m[j]!=m[st.top()])
             {
                if(m[j]>m[st.top()])
               {
                 break;
               }
               else
               {
                  ob+=m[st.top()]-m[j];
               }
              j++;
             }


        }
    }
cout<<br<<" "<<ob<<endl;
}
/*
6
2 4 2 4 2 1
2
2 1
4 1
*/

