#include<iostream>
using namespace std;
 long long broi[28];
 long long broi2[28];
int main(){
long long N,M,K;
cin>>N>>M>>K;
if(M==1){
    string a;
    for(long long i=0;i<N;i++){
        cin>>a;
    }
    cout<<N<<"\n"<<"a"<<"\n"<<1<<endl;
    return 0;
}if(M==2){
    long long broi=0,broi2=0,broi3=0,broi4=0;
    string a;
    for(long long i=0;i<N;i++){
        bool dali=0,dali2=0,dali3=0,dali4=0;
        cin>>a;
        for(long long j=0;j<N && (dali==0 || dali2==0);j++){
            if(a[j]=='a'){
                dali3=1;
                for(long long k=j+1;k<N;k++){
                    if(a[k]=='b'){
                        dali4=1;
                        dali=1;
                    }
                }
            }else{
                dali4=1;
                for(long long k=j+1;k<N;k++){
                    if(a[k]=='a'){
                        dali3=1;
                        dali2=1;
                    }
                }
            }
        }
        broi+=dali;
        broi2+=dali2;
        broi3+=dali3;
        broi4+=dali4;
    }
    if(K==1){
         if(broi3==broi4){
            cout<<broi3<<"\n"<<"a"<<"\n"<<2<<endl;
        }else{
            if(broi4>broi3){
                     cout<<broi4<<"\n"<<"b"<<"\n"<<1<<endl;
            }else{
                     cout<<broi3<<"\n"<<"a"<<"\n"<<1<<endl;
            }
        }
    }if(K==2){
        if(broi2==broi){
            cout<<broi<<"\n"<<"ab"<<"\n"<<2<<endl;
        }else{
            if(broi2>broi){
                     cout<<broi2<<"\n"<<"ba"<<"\n"<<1<<endl;
            }else{
                     cout<<broi<<"\n"<<"ab"<<"\n"<<1<<endl;
            }
        }
    }
    return 0;
}
if(K==1){
    string a;
    for(long long i=0;i<N;i++){
        cin>>a;
        for(long long j=0;j<a.size();j++){
            broi[a[j]-'a']=1;
        }
        for(long long j=0;j<=28;j++){
            broi2[j]+=broi[j];
            broi[j]=0;
        }
    }
    long long nai=0,kolko=0;
    char bu;
    for(long long i=0;i<=28;i++){
            if(broi2[i]>nai){
                kolko=0;
                nai=broi2[i];
                bu='a'+i;
            }if(broi2[i]==nai){
                kolko++;
            }
    }
    cout<<nai<<endl<<bu<<endl<<kolko<<endl;
    return 0;
}
cout<<0<<endl;
return 0;
}
