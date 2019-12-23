#include<iostream>
using namespace std;
long long broi[27];
long long broi2[27];
int main(){
long long N,M,K;
cin>>N>>M>>K;
string a;
for(long long i=0;i<N;i++){
    cin>>a;
    for(long long j=0;j<a.size();j++){
        broi[a[j]-'a']=1;
    }for(long long j=0;j<30;j++){
        broi2[j]+=broi[j];
        broi[j]=0;
    }
}
long long nai=0;
for(long long i=0;i<30;i++){
    if(broi2[i]>broi2[nai]){
        nai=i;
    }
}
long long kolko=0;
for(long long i=0;i<30;i++){
    if(broi2[i]==broi2[nai]){
        kolko++;
    }
}
cout<<broi2[nai]<<endl<<char(nai+'a')<<endl<<kolko<<endl;
return 0;
}
