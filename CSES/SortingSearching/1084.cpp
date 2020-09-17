#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int apartment[MAXN],desire[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin>>n>>m>>k;
    
    for(int i=0;i<n;++i){
        cin>>desire[i];
    }
    for(int i=0;i<m;++i){
        cin>>apartment[i];
    }

    sort(desire,desire+n);
    sort(apartment,apartment+m);

    int res=0,applicant=0;
    for(int i=0;i<m;++i){
        while(applicant<n and desire[applicant]<apartment[i]-k){
            ++applicant;
        }
        if(applicant<n and desire[applicant]<=apartment[i]+k){
            ++res;
            ++applicant;
        }
    }

    cout<<res<<endl;
return 0;
}