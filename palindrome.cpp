#include<bits/stdc++.h>
using namespace std;
string create_pal(string pali){
    int n=pali.length(),i2=0;
    for(int i=n-1;i>=n/2+((n/2)%2==1);i--){
        pali[i]=pali[i2];
        i2++;
    }
    return pali;
}
string increase_pal(string pali){
    string rez="";
    int n=pali.length();
    for(int i=0;i<n/2+(n%2==1);i++){
        rez+=pali[i];
    }
    bool j=false;
    for(int i=n/2-1+(n%2==1);i>=0;i--){
        if(rez[i]<'9'){
            rez[i]++;
            break;
        }else{
            if(i==0){
                rez[i]='1';
                j=true;
            }else rez[i]='0';
        }
    }
    string rez2="";
    for(int i=0;i<n/2;i++){
        rez2+=rez[i];
    }
    if(j) rez+='0';
    reverse(rez2.begin(),rez2.end());
    rez+=rez2;
    return rez;
}
bool compare_pal(string pali1,string pali2){
    if(pali1.length()>pali2.length()) return false;
    else if(pali2.length()>pali1.length()) return true;
    else{
        for(int i=0;i<pali1.length();i++)
            if(pali1[i]<pali2[i])
                return true;
            else if(pali1[i]>pali2[i])
                return false;
        return true;
    }
}
int main(){
    string pal,new_pal="";
    cin>>pal;
    new_pal=create_pal(pal);
    while(compare_pal(new_pal,pal)){
         new_pal=increase_pal(new_pal);
    }
    cout<<new_pal<<endl;
return 0;
}