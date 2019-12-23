#include<bits/stdc++.h>
using namespace std;
long long hodove[1000];
long long a[100000];
long long suma1[100000];
long long suma2[100000];
long long p[100000];
int n,k;
void slowSorting(){
    for(int i=0;i<k;i++){
        p[hodove[i]]++;
    }
    int h=0;
    for(int i=0;i<1001;i++){
        while(p[i]!=0){
            hodove[h]=i;
            p[i]--;
            h++;
        }
    }
}

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++){
        suma1[i]=-100000;
        suma2[i]=-100000;
    }
    long long maxHod=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k;i++){
        cin>>hodove[i];
        maxHod=max(maxHod,hodove[i]);
    }
    if(maxHod<=10000){
        slowSorting();
    }else{
        sort(hodove,hodove+k);
    }
    for(int i=0;i<hodove[0];i++){
        suma1[i]=a[i];
    }
    suma1[hodove[0]]=a[0]+a[hodove[0]];
    for(int i=hodove[0]+1;i<n;i++){
        for(int j=0;j<k;j++){
            if(i>=hodove[j]){
                suma1[i]=max(suma1[i-hodove[j]]+a[i],suma1[i]);
                //cout<<suma1[i]<<" ";
            }
            //cout<<"*";
        }
        //cout<<endl;
    }
    //cout<<"*";
    for(int i=n-1;i>=n-1-hodove[0];i--){
        suma2[i]=a[i];
    }
    suma2[n-1-hodove[0]]=a[n-1-hodove[0]]+a[n-1];
    for(int i=n-2-hodove[0];i>=0;i--){
        for(int j=0;j<k;j++){
                //cout<<"*";
            if(i<n-hodove[j]-1){
                suma2[i]=max(suma2[i+hodove[j]]+a[i],suma2[i]);
                //cout<<"*";
            }
        }
    }
    /*for(int i=0;i<n;i++){
        cout<<suma2[i]<<" ";
    }
    */
    long long maxSum=-1;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            maxSum=max(maxSum,suma1[i]+suma2[j]);
        }
    }
    cout<<maxSum;
    /*for(int i=0;i<k;i++){
        cout<<hodove[i];
    }
    */

   /* int a,b;
    cin>>b>>a;
    if(b>=a)
    {
        while(b!=0 and a!=0)
        {
            if(b>=a)
            {
                b=b%a;
            }
            else
            {
                a=a%b;
            }
        }
    }
    else
    {
        swap(a,b);
        while(b!=0)
        {
            if(b>=a)
            {
                b=b%a;
            }
            else
            {
                a=a%b;
            }
        }
        cout<<a;
    }
    */
    return 0;
}
