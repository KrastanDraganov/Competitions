#include<iostream>
using namespace std;
int broi[27];
int main(){
long long N,M,K;
cin>>N>>M>>K;
string a;
for(long long i=0;i<N;i++){
    cin>>a;
    for(long long j=0;j<a.size();j++){
        broi[a[j]-'a']++;
    }
}
long long nai=0;
for(long long i=0;i<30;i++){
    if(broi[i]>broi[nai]){
        nai=i;
    }
}
long long kolko=0;
for(long long i=0;i<30;i++){
    if(broi[i]==broi[nai]){
        kolko++;
    }
}
cout<<broi[nai]<<endl<<char(nai+'a')<<endl<<kolko<<endl;
return 0;
}
